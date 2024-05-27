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
