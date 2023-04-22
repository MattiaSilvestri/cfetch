#include "modules.h"
#include <array>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // cout << model() << endl;
  // cout << get_ram() << endl;
  // cout << get_cpu() << endl;
  // // cout << get_res() << endl;
  // cout << get_user() << endl;
  // cout << get_os() << endl;
  // cout << get_kernel() << endl;
  // cout << get_de() << endl;
  // cout << get_pkgs() << endl;
  // cout << get_shell() << endl;
  // cout << "\n";
  // cout << "--------------------------" << endl;
  // cout << "\n";

  // system(("echo -e " + colours_dark()).c_str());
  // system(("echo -e " + colours_light()).c_str());

  // Get colours
  string dark = exec(("echo " + colours_dark()).c_str());
  string light = exec(("echo " + colours_light()).c_str());

  array<string, 14> fetch;
  const int rm{88}; // Characters to remove when computing paddings
  fetch[0] = "╭─────────────────── System info ───────────────────╮";

  // Define paddings
  int total_len = fetch[0].length();
  int model_pad = total_len - model().length() - rm;
  int ram_pad = total_len - get_ram().length() - rm;
  int cpu_pad = total_len - get_cpu().length() - rm;
  int user_pad = total_len - get_user().length() - rm;
  int os_pad = total_len - get_os().length() - rm;
  int kernel_pad = total_len - get_kernel().length() - rm;
  int de_pad = total_len - get_de().length() - rm;
  int pkgs_pad = total_len - get_pkgs().length() - rm;
  int shell_pad = total_len - get_shell().length() - rm;
  int colour_pad = total_len - dark.length() + 13;

  // Display system info
  fetch[1] = "│    " + model() + string(model_pad, ' ') + "│";
  fetch[2] = "│    " + get_ram() + string(ram_pad, ' ') + "│";
  fetch[3] = "│    " + get_cpu() + string(cpu_pad, ' ') + "│";
  fetch[4] = "│    " + get_user() + string(user_pad, ' ') + "│";
  fetch[5] = "│    " + get_os() + string(os_pad, ' ') + "│";
  fetch[6] = "│    " + get_kernel() + string(kernel_pad, ' ') + "│";
  fetch[7] = "│    " + get_de() + string(de_pad, ' ') + "│";
  fetch[8] = "│    " + get_pkgs() + string(pkgs_pad, ' ') + "│";
  fetch[9] = "│    " + get_shell() + string(shell_pad, ' ') + "│";

  fetch[10] = "├───────────────────────────────────────────────────┤";
  fetch[11] = "│ " + dark + string(colour_pad, ' ') + "│";
  fetch[12] = "│ " + light + string(colour_pad, ' ') + "│";
  fetch[13] = "╰───────────────────────────────────────────────────╯";

  cout << fetch[0] << endl;
  cout << fetch[1] << endl;
  cout << fetch[2] << endl;
  cout << fetch[3] << endl;
  cout << fetch[4] << endl;
  cout << fetch[5] << endl;
  cout << fetch[6] << endl;
  cout << fetch[7] << endl;
  cout << fetch[8] << endl;
  cout << fetch[9] << endl;
  cout << fetch[10] << endl;
  cout << fetch[11] << endl;
  cout << fetch[12] << endl;
  cout << fetch[13] << endl;
}
