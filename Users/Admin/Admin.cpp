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

void Admin::changeTesterAddress(Tester* tester, string address)
{
    try
    {
        tester->changeAddress(address);
    }
    catch (const logic_error& err)
    {
        cout << ERROR_COLOR << "Ошибка: " << err.what() << RESET_COLOR << endl;
    }
}

void Admin::changeTesterPhone(Tester* tester, string phone)
{
    try
    {
        tester->changePhone(phone);
    }
    catch (const exception& err)
    {
        cout << ERROR_COLOR << "Ошибка: " << err.what() << RESET_COLOR << endl;
    }
}