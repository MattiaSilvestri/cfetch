#include "../modules.h"
#include <cstddef>
#include <fstream>
#include <string>
#include <array>
using namespace std;

// Get screen resolution
string get_res()
{
    string xrandr;
    array<string, 2> res;
    xrandr = system("xrandr -q|grep \"connected\"");

    int count {};
    size_t pos {}, current_pos {};
    while (current_pos != string::npos) {
        current_pos = xrandr.find("connected", pos);
        res[count] = xrandr.substr(current_pos + 2, 1);
        if (current_pos != string::npos) {
            pos = current_pos + 1;
        }
        ++count;
    }

    string s_out {};
    for (string i : res) {
        s_out = s_out + i + "\n";
    }

    return s_out;
}
