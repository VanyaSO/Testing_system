#pragma once
#include "../Menu.h"
#include "../../TestManager/TestManager.h"
#include "../../FileWriteReadTest/FileWriteReadTest.h"
#include "../../Test/Test.h"
class AdminMenu: public Menu
{
public:
    static void adminMenu();
    static void adminMenuUserManagement();
    static void adminMenuStatistics();
    static void adminMenuTestManagement();
};
