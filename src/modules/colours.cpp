#include "../modules.h"

using namespace std;

string colours_dark() {
    string s, colour_icon = "󰄯";

    // Print coloured full circles
    for (int i = 30; i < 38; ++i)
        s += "\e["+to_string(i)+"m"+colour_icon+"\e[0m ";

    return s;
}

string colours_light() {
    string s, colour_icon = "󰄯";

    // Print coloured full circles
    for (int i = 90; i < 98; ++i)
        s += "\e["+to_string(i)+"m"+colour_icon+"\e[0m ";

    return s;
}
