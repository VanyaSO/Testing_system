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
#include <filesystem>

int main()
{
    //перенести из мейн куда то
    string file_name = "data/dataTest";

    if (!filesystem::exists(file_name)) //проверка существуют ли папки
    {
        filesystem::create_directories(file_name);//создание пап
    }
    file_name = "data/users";

    if (!filesystem::exists(file_name)) //проверка существуют ли папки
    {
        filesystem::create_directories(file_name);//создание пап
    }



    locale::global(std::locale("ru_RU.UTF-8"));

    FileWriteReadUsers::loadUsersFromFile();
 
    Menu::mainMenu();

    FileWriteReadUsers::saveUsersToFile();

    for (int i = 0; i < arrayUser.size(); ++i) {
        delete arrayUser[i];
    }
    return 0;
}