#include <string>

std::string model();
std::string get_ram();
std::string get_cpu();
std::string get_res();
std::string get_user();
std::string get_os();
std::string get_kernel();
std::string get_de();
std::string get_pkgs();
std::string get_shell();
std::string get_term();
std::string get_host();
std::string colours_dark();
std::string colours_light();

// Custom functions
std::string exec(const char *cmd);
