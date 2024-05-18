#include "Menu.h"
#include "./AdminMenu/AdminMenu.h"
#include "../common/Common/Common.h"
#include "../common/config.h"

bool isArrayAdminFull = true;

int Menu::getActionMenu(int max, int min) {
    int action;
    while(true)
    {
        try
        {
            action = Common::getAction(max, min);
            break;
        }
        catch (const invalid_argument& error)
        {
            cout << ERROR_COLOR << error.what() << ": не допустимое значение, попробуйте еще раз" << RESET_COLOR << endl;
        }
        catch (const out_of_range& error)
        {
            cout << ERROR_COLOR << error.what() << ": нет подходящего варинта, попробуйте еще раз" << RESET_COLOR << endl;
        }
    }
    return action;
}

void Menu::mainMenu()
{
    // проверка есть ли у нас админ
    if (isArrayAdminFull)
    {
        cout << "Регистрация администратор" << endl;
        isArrayAdminFull = false;
        //TODO: регистрация админа;
        //TODO: открытие меню админа;
    }

    cout << "Главное меню" << endl;
    cout << "1) Вход" << endl;
    cout << "2) Регистрация" << endl;
    cout << "0) Завершить работу програмы" << endl;

    int action = getActionMenu(2);

    switch (action)
    {
        case 1:
            cout << "Делаем Вход" << endl;
            break; //TODO: функция входа для юзера
        case 2:
            cout << " Делаем Регистрацию" << endl;
            break; //TODO: функция регистрации для юзера
        case 0:
            exit(0);
    }


    //TODO: после входа будет проверка кто зашел в
    // систему и исходя от этого принтить подходяее меню
    AdminMenu::adminMenu();
    mainMenu();
}

