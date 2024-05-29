#ifndef TESTING_SYSTEM_TESTERMENU_H
#define TESTING_SYSTEM_TESTERMENU_H
#include "../Menu.h"
#include "../../TestManager/TestManager.h"
#include "../../FileWriteReadTest/FileWriteReadTest.h"
#include "../../common/config.h"

class TesterMenu: public Menu
{
public:
    static void testerMenu();
};


#endif
