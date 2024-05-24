#include "./config.h"
const char* ERROR_COLOR = "\033[1;31m";
const char* SUCCESSFUL_COLOR = "\033[1;32m";
const char* WARNING_COLOR = "\033[1;33m";
const char* RESET_COLOR = "\033[0m";

User* user = nullptr;
vector<User*> arrayUser;

const int passMinSize = 6;
//string path_file_admin = "../data/users/admin.dat";

//string path_file_admin = "../../../data/users/admin.dat";
//string path_file_tester = "..\\data\\users\\tester.dat";


#ifdef __APPLE__
// Код для MacOS
string path_file_admin = "../data/users/admin.dat";
string path_file_tester = "../data/users/tester.dat";


#elif defined(_WIN32) || defined(_WIN64)
// Код для Windows

string path_file_admin = "../../../data/users/admin.dat";
string path_file_tester = "../../../data/users/tester.dat";

#else
// Код для других ОС
//path_file_admin = "default/path/to/admin.dat";
#endif
