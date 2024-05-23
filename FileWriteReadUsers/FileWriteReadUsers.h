#ifndef TESTING_SYSTEM_FILEWRITEREADUSERS_H
#define TESTING_SYSTEM_FILEWRITEREADUSERS_H
#include "../Users/User.h"

class FileWriteReadUsers {
    static void writeStr(string str, fstream& file);
    static string readStr(fstream& file);
public:
    static void saveUsersToFile();
    static void loadUsersFromFile();
};


#endif
