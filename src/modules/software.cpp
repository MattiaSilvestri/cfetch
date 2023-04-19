#include "../modules.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <filesystem>
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

string get_pkgs() {
    string pkg;

    // pacman
    if (filesystem::exists("/bin/pacman"))
        pkg = pkg + exec("pacman -Qq | wc -l") + " (pacman) ";

    // dpkg
    if (filesystem::exists("/bin/dpkg"))
       pkg = pkg + exec("dpkg --get-selections | wc -l") + " (dpkg) ";

    // nix
    if (filesystem::exists("/nix"))
    {
        if(filesystem::exists("/etc/nix"))
            pkg = pkg + exec("nix-store --query --requisites /run/current-system | wc -l");
        else
            pkg = pkg + exec("nix-env -q | wc -l");

        pkg = pkg + " (nix) ";
    }

    // portage
    if (filesystem::exists("/bin/emerge"))
        pkg = pkg + exec("echo -n $(cd /var/db/pkg && ls -d */* | wc -l") + " (emerge) ";

    // rpm
    if (filesystem::exists("/var/lib/rpm"))
        pkg = pkg + exec("rpm -qa | wc -l") + " (rpm) ";

    // XBPS
    if (filesystem::exists("/bin/xbps-install"))
        pkg = pkg + exec("xbps-query -l | wc -l") + " (xbps) ";


    // Snap
    if (filesystem::exists("/bin/snap"))
    {
        string n_snap = exec("snap list | wc -l");
        n_snap = std::to_string(std::stoi(n_snap) - 1);
        pkg = pkg + n_snap + " (snap) ";
    }

    // flatpak
    if (filesystem::exists("/bin/flatpak"))
        pkg = pkg + exec("flatpak list | wc -l") + " (flatpak) ";

    return pkg;

}

string get_shell() {
    return getenv("SHELL");
}
