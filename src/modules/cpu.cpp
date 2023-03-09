#include "../modules.h"
#include <fstream>
#include <string>
using namespace std;

// Read cpu model
string get_cpu() {
    string line, cpu_name;

    // Read cpuinfo file
    ifstream cpuinfo("/proc/cpuinfo");

    while (cpuinfo.good()) {
        getline(cpuinfo, line);
        if (line.find("model name") != string::npos) {
            cpu_name = line.substr(line.find(":") + 2);
            break;
        }
    }

    cpuinfo.close();
    string s_out = cpu_name;

    return s_out;
}
