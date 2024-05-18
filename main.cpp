#include <iostream>
using namespace std;
#include <string>
//#include "./common/config.h"
#include "Users/User.h"
#include "Users/Tester/Tester.h"
#include "Users/Admin/Admin.h"
#include "Menu/Menu.h"
#include "FileWriteReadTest/FileWriteReadTest.h"
#include "Test/Test.h"
#include "Test/Question/Question.h"



int main()
{
    setlocale(LC_ALL, " ");
    Tester tst("MyLogin", "MyPass", "MyName", "MySname", "MyLastName", "MyAddress", "0961112233");
    tst.show();

    Admin adm("LOGIN", "PASSWORD");
    adm.show();

    Menu::mainMenu();


    return 0;
}