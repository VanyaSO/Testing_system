#include "Menu.h"
#include "./AdminMenu/AdminMenu.h"
#include "../common/Common/Common.h"
#include "../common/config.h"
#include "../Users/Admin/Admin.h"
#include "../Users/Tester/Tester.h"
#include "./TesterMenu/TesterMenu.h"

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
    if (arrayUser.empty())
    {
        cout << "Регистрация администратора" << endl;
        user = new Admin;
        user->Register();
        cout << SUCCESSFUL_COLOR << "Aдминистратор зарегистрирован!" << RESET_COLOR << endl;
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
            user = User::Login();
            if (user != nullptr) cout << SUCCESSFUL_COLOR << "Вход успешен!" << RESET_COLOR << endl;
            break;
        case 2:
            cout << " Делаем Регистрацию" << endl;
            user = new Tester;
            user->Register();
            break; //TODO: функция регистрации для юзера
        case 0:
            return;
    }

    if (user != nullptr)
    {
        if (user->getRole() == "admin")
        {
            cout << "admin" << endl;
            AdminMenu::adminMenu();
        }
        else if (user->getRole() == "tester")
        {
            cout << "tester" << endl;
            TesterMenu::testerMenu();
        }

        
    }

    mainMenu();
}

