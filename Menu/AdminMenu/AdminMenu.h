#ifndef TESTING_SYSTEM_ADMINMENU_H
#define TESTING_SYSTEM_ADMINMENU_H
#include "../Menu.h"

class AdminMenu: public Menu
{
public:
    static void adminMenu();
    static void adminMenuUserManagement();
    static void adminMenuStatistics();
    static void adminMenuTestManagement();
};


#endif
