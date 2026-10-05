#include "modules.h"
#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

// Function to get the outout of a shell command
// Taken from stack overflow:
// https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po
std::string exec(const char *cmd) {
  std::array<char, 128> buffer;
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  return result.substr(0, result.length() - 1);
}

size_t visible_width(const std::string &s) {
  // Count visible characters
  size_t w = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '\e') { // (A) colour code: skip it
      while (i < s.size() && s[i] != 'm')
        ++i;
      continue;
    }
    if ((static_cast<unsigned char>(s[i]) & 0xC0) != 0x80) // (B)
      ++w;
  }
  return w;
}
