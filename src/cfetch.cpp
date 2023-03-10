#include "modules.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << model() << endl;
    cout << get_ram() << endl;
    cout << get_cpu() << endl;
    // cout << get_res() << endl;
    cout << get_user() << endl;
    cout << get_os() << endl;
    cout << get_kernel() << endl;
    cout << get_de() << endl;
    cout << get_pkgs() << endl;
    cout << get_shell() << endl;
}
