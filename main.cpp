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


int main()
{
    // #include <windows.h>    // byte is ambiguous symbol
    //SetConsoleCP(1251);      // меню в кракозябрах
    //SetConsoleCP(866);

    Admin testAdm("admin", "admin");
    arrayUser.push_back(&testAdm);


    setlocale(LC_ALL, " ");



    //Tester toster;
    //toster.Register();
    //toster.show();

    //Tester* toster = new Tester;
    //toster->show();

    //Tester toster;
    //toster.show();
    //arrayUser.push_back(&toster);


    // выгрузка админов в массив
    // выгрузка тестеров в массив
    // выгрузка тестов
    Menu::mainMenu();


    //for (int i = 0; i < arrayUser.size(); ++i) {
    //    delete arrayUser[i];
    //}

    return 0;
}