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
    //????????? ?? ???? ???? ??
//    string file_name = "data/dataTest";
//
//    if (!filesystem::exists(file_name)) //???????? ?????????? ?? ?????
//    {
//        filesystem::create_directories(file_name);//???????? ???
//    }
//    file_name = "data/users";
//
//    if (!filesystem::exists(file_name)) //???????? ?????????? ?? ?????
//    {
//        filesystem::create_directories(file_name);//???????? ???
//    }

    locale::global(std::locale("ru_RU.UTF-8"));

    FileWriteReadUsers::loadUsersFromFile();
 
    cout << "MY TEST: " << endl;

    string str = "dwad";
    Admin* admin = dynamic_cast<Admin*>(user);
    Tester* tester = dynamic_cast<Tester*>(arrayUser[1]);
    admin->changeTesterPhone(tester, str);
    //Menu::mainMenu();

    FileWriteReadUsers::saveUsersToFile();
    cout << "check:";
    string check;
    cin >> check;
    //for (int i = 0; i < arrayUser.size(); ++i) {
    //    delete arrayUser[i];
    //}
    return 0;
}