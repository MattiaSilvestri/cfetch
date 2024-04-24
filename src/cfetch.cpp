#include "modules.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <array>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace rapidjson;

int main() {

  // Config folder
  string conf;
  const char *xdg_config_home = getenv("XDG_CONFIG_HOME");
  if (xdg_config_home) {
    conf = string(xdg_config_home) + "/cfetch/config.json";
  } else {
    const char *home = getenv("HOME");
    if (home) {
      conf = string(home) + "/.config/cfetch/config.json";
    } else {
      // Handle the case where HOME environment variable is not set
      cerr << "Error: HOME environment variable not set" << endl;
      return 1;
    }
  }

  // Get colours
  string dark = exec(("echo " + colours_dark()).c_str());
  string light = exec(("echo " + colours_light()).c_str());

  vector<string> fetch{};
  const int rm{88}; // Characters to remove when computing paddings
  fetch.push_back("╭─────────────────── System info ───────────────────╮");

  // Define paddings
  int total_len = fetch[0].length();
  int model_pad = total_len - model().length() - rm;
  int ram_pad = total_len - get_ram().length() - rm;
  int cpu_pad = total_len - get_cpu().length() - rm;
  int user_pad = total_len - get_user().length() - rm;
  int host_pad = total_len - get_host().length() - rm;
  int os_pad = total_len - get_os().length() - rm;
  int kernel_pad = total_len - get_kernel().length() - rm;
  int de_pad = total_len - get_de().length() - rm;
  int pkgs_pad = total_len - get_pkgs().length() - rm;
  int shell_pad = total_len - get_shell().length() - rm;
  int term_pad = total_len - get_term().length() - rm;
  int colour_pad = total_len - dark.length() + 13;

  // Display system info
  fetch.push_back("│    " + model() + string(model_pad, ' ') + "│");
  fetch.push_back("│    " + get_ram() + string(ram_pad, ' ') + "│");
  fetch.push_back("│    " + get_cpu() + string(cpu_pad, ' ') + "│");
  fetch.push_back("│    " + get_user() + string(user_pad, ' ') + "│");
  fetch.push_back("│    " + get_host() + string(host_pad, ' ') + "│");
  fetch.push_back("│    " + get_os() + string(os_pad, ' ') + "│");
  fetch.push_back("│    " + get_kernel() + string(kernel_pad, ' ') +
                  "│");
  fetch.push_back("│    " + get_de() + string(de_pad, ' ') + "│");
  fetch.push_back("│    " + get_pkgs() + string(pkgs_pad, ' ') + "│");
  fetch.push_back("│    " + get_shell() + string(shell_pad, ' ') + "│");
  fetch.push_back("│    " + get_term() + string(term_pad, ' ') + "│");

  fetch.push_back("├───────────────────────────────────────────────────┤");
  fetch.push_back("│ " + dark + string(colour_pad, ' ') + "│");
  fetch.push_back("│ " + light + string(colour_pad, ' ') + "│");
  fetch.push_back("╰───────────────────────────────────────────────────╯");

  for (size_t i{}; i < fetch.size(); ++i) {
    cout << fetch[i] << endl;
  }

  // Open the file for reading
  FILE *fp = fopen(conf.c_str(), "r");

  // Use a FileReadStream to
  // read the data from the file
  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

  // Parse the JSON data
  // using a Document object
  rapidjson::Document d;
  d.ParseStream(is);

  // Close the file
  fclose(fp);

  // Access the data in the JSON document
  cout << d["a"].GetString() << std::endl;
}
