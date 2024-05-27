#include "Admin.h"
#include "../../common/config.h"
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

ostream& operator<<(ostream& out, Admin& admin)
{
    out << "Логин: " << admin.getLogin() << "\n"
    << "Пароль: " << admin.getPassword() << "\n" << endl;
    return out;
}
