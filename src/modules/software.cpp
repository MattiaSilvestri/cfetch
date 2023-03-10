#include "../modules.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

string get_user() {
    // Get user name
    return getenv("USER");
}

string get_os() {
    // Get operating system name
    string line, os_name;

    // Read /etc/os-release file
    ifstream infile("/etc/os-release");

    while(infile.good()) {
        getline(infile, line);
        if (line.find("PRETTY_NAME") != string::npos) {
            os_name = line.substr(line.find("=") + 1);
            break;
        }
    }
    infile.close();

    // Remove ""
    os_name = os_name.substr(1, os_name.length() - 2);

    return os_name;
}

string get_kernel() {
    // Get kernel version
    string kernel;

    // Read /proc/sys/kernel/osrelease
    ifstream infile("/proc/sys/kernel/osrelease");
    getline(infile, kernel);
    infile.close();

    return kernel;
}

string get_de() {
    // Get current Desktop environment
    const char* de;

    if (
        (de = getenv("XDG_CURRENT_DESKTOP")) or
        (de = getenv("DESKTOP_SESSION")) or
        (de = getenv("XDG_SESSION_DESKTOP")) or
        (de = getenv("CURRENT_DESKTOP")) or
        (de = getenv("SESSION_DESKTOP"))
    )
        return string(de);
    else
        return string("No DE found");
}
