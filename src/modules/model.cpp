#include <iostream>
#include <fstream>
#include <string>
#include "../modules.h"
using namespace std;

string model() {
    string name, version;
    // Read product_name file
    ifstream model_name("/sys/devices/virtual/dmi/id/product_name");
    getline(model_name, name);
    model_name.close();

    // Read product version
    ifstream model_version("/sys/devices/virtual/dmi/id/product_version");
    getline(model_version, version);
    model_version.close();

    string s_out = name + " " + version;
    return s_out;
}
