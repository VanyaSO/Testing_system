#include <iostream>
using namespace std;
#include <string>
#include "./common/config.h"
#include "Users/User.h"
#include "Users/Tester/Tester.h"
#include "Users/Admin/Admin.h"
#include "Menu/Menu.h"
#include "FileWriteReadTest/FileWriteReadTest.h"
#include "Test/Test.h"
#include "Test/Question/Question.h"
#include "./FileWriteReadUsers/FileWriteReadUsers.h"
#include "TestManager/TestManager.h"
#include "Test/Test.h"

int main()
{

    locale::global(std::locale("ru_RU.UTF-8"));

    FileWriteReadUsers::loadUsersFromFile();
 
    Menu::mainMenu();

    FileWriteReadUsers::saveUsersToFile();

    for (int i = 0; i < arrayUser.size(); ++i) {
        delete arrayUser[i];
    }
    return 0;
}