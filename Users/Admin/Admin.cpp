#include "Admin.h"
#include "../../common/config.h"
void Admin::show()
{
	cout << "Admin Login: " << _login << "\n" << "Admin Passw: " << _password << "\n" << "Admin Role: " << _role << endl << endl;
}

void Admin::Register()
{
    while (true)
    {
        cout << "Введите логин: " << endl;
        cin >> _login;

        if (this->isUserRegistered())
        {
            cout << ERROR_COLOR << "Пользователь уже существует" << RESET_COLOR << endl;
            continue;
        }
        break;
    }

    cout << "Введите пароль: " << endl;
    cin >> _password;

    arrayUser.push_back(this);
}

void Admin::changeTesterAddress(string login, string address)
{
    for (User* el : arrayUser)
    {
        if (el->getRole() == "tester" && el->getLogin() == login)
        {
            Tester* tester = dynamic_cast<Tester*>(el);
            tester->setAddress(address);
            cout << SUCCESSFUL_COLOR << "Адрес успешно изменен." << RESET_COLOR << endl;
            return;
        }
    }
    cout << ERROR_COLOR << "Тестировщик с таким логином не найден." << RESET_COLOR << endl;
}

void Admin::changeTesterPhone(string login, string phone)
{
    for (User* el : arrayUser)
    {
        if (el->getRole() == "tester" && el->getLogin() == login)
        {
            Tester* tester = dynamic_cast<Tester*>(el);
            try
            {
                tester->setPhone(phone);
                cout << SUCCESSFUL_COLOR << "Телефон успешно изменен." << RESET_COLOR << endl;
            }
            catch (const invalid_argument& er)
            {
                cout << ERROR_COLOR << "Ошибка: " << er.what() << RESET_COLOR << endl;
            }
            return;
        }
    }
    cout << ERROR_COLOR << "Тестировщик с таким логином не найден." << RESET_COLOR << endl;
}
