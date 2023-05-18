#include "modules.h"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
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
}
