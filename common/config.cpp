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
// ��� ��� MacOS
string path_file_admin = "../data/users/admin.dat";
string path_file_tester = "../data/users/tester.dat";
string path_to_results = "../data/results.txt";
string path_to_test = "../data/dataTest";

#elif defined(_WIN32) || defined(_WIN64)
// ��� ��� Windows
string path_file_admin = "../../../data/users/admin.dat";
string path_file_tester = "../../../data/users/tester.dat";
string path_to_results = "../../../data/results.txt";
string path_to_test = "../../../data/dataTest";

#else
// ��� ��� ������ ��
string path_file_admin = "../../../data/users/admin.dat";
string path_file_tester = "../../../data/users/tester.dat";


#endif
