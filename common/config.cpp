#include "./config.h"

const char* ERROR_COLOR = "\033[1;31m";
const char* SUCCESSFUL_COLOR = "\033[1;32m";
const char* WARNING_COLOR = "\033[1;33m";
const char* RESET_COLOR = "\033[0m";

User* user = nullptr;
vector<User*> arrayUser;

const int passMinSize = 6;
string path_file_admin = "../data/users/admin.dat";