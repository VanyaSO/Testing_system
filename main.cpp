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


int main()
{
    // #include <windows.h>    // byte is ambiguous symbol
    //SetConsoleCP(1251);      // меню в кракозябрах
    //SetConsoleCP(866);

//     Admin testAdm("admin", "admin");
//     arrayUser.push_back(&testAdm);

    setlocale(LC_ALL, " ");

    Tester toster;
    toster.Register();
    toster.show();

    //Tester* toster = new Tester();
    //toster->Register();
    //toster->show();

    //Tester toster("login1","pass1","name1","sName1","LName1","address1","phone1");
    //toster.show();




    // выгрузка админов в массив
    // выгрузка тестеров в массив
    // выгрузка тестов
    //Menu::mainMenu();

    FileWriteReadUsers::loadUsersFromFile();
 
    Menu::mainMenu();

    FileWriteReadUsers::saveUsersToFile();

    for (int i = 0; i < arrayUser.size(); ++i) {
        delete arrayUser[i];
    }
    return 0;
}