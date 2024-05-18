#include <iostream>
using namespace std;
#include <string>
#include "Users/User.h"
#include "Users/Tester/Tester.h"
#include "Users/Admin/Admin.h"
#include "Menu/Menu.h"
#include "FileWriteReadTest/FileWriteReadTest.h"
#include "Test/Test.h"
#include "Test/Question/Question.h"



int main()
{
    Menu::mainMenu();
    Tester tst("MyLogin", "MyPass", "Role", "MyName", "MySname", "MyLastName", "MyAddress", "0961112233");
    tst.show();

    Admin adm("LOGIN", "PASSWORD", "ROLE");
    adm.show();


    return 0;
}