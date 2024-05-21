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
    Admin testAdm("admin", "admin");
    arrayUser.push_back(&testAdm);

    setlocale(LC_ALL, " ");
    // выгрузка админов в массив
    // выгрузка тестеров в массив
    // выгрузка тестов
    Menu::mainMenu();

    for (int i = 0; i < arrayUser.size(); ++i) {
        delete arrayUser[i];
    }

    return 0;
}