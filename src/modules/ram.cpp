#include "../modules.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string get_ram() {
    // Get total available ram
    string line;
    int total_ram {};
    // Read mem info
    ifstream ram("/proc/meminfo");

    while (ram.good()) {
        ram >> line >> total_ram;
        if (line == "MemTotal:") {
            break;
        }
    }
    ram.close();

    string s_out;
    s_out = to_string(total_ram / 1024) + "MiB";

    return s_out;
}
