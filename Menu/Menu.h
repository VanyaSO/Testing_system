#ifndef TESTING_SYSTEM_MENU_H
#define TESTING_SYSTEM_MENU_H
#include <iostream>
using namespace std;


class Menu
{
protected:
    static int getAction(int maxVarAction, int minVarAction=0);
public:
    static int getActionMenu(int, int=0);
    static void mainMenu();
};




#endif
