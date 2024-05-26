#include "User.h"
#include "./Admin/Admin.h"
#include "../common/config.h"
#include "../Menu/Menu.h"
#include "Tester/Tester.h"
User::User(string login, string pass, string role)
{
    _login = login;
    _password = pass;
    _role = role;
}

string User::getLogin() const { return _login; }
string User::getPassword() const { return _password; }
string User::getRole() const { return _role; }

int User::authentication(string login, string password)
{
    bool isRegistered = false;

    if (!arrayUser.empty())
    {
        for (int i = 0; i < arrayUser.size(); ++i)
        {
            if (arrayUser[i]->_login.compare(login) == 0)
            {
                // ставим флаг что пользователь такой есть
                isRegistered = true;
                // проверяем пароль
                if (arrayUser[i]->_password.compare(password) == 0)
                {
                    return i;
                }
                throw invalid_argument("Неверно введены данные");
            }
        }
    }

    if (!isRegistered)
        throw logic_error("Пользователя не существует");
}

bool User::isUserRegistered()
{
    for (int i = 0; i < arrayUser.size(); ++i)
    {
        if (arrayUser[i]->_login == _login)
            return true;
    }
    return false;
}

User* User::Login()
{
    string login;
    string password;
    unsigned int index;

    cout << "Введите логин: " << endl;
    cin >> login;

    cout << "Введите пароль: " << endl;
    cin >> password;


    try
    {
        index = authentication(login, password);
        return arrayUser[index];
    }
    catch (const invalid_argument& error)
    {
        cout << ERROR_COLOR << error.what() << RESET_COLOR << endl;
        return nullptr;
    }
    catch (const logic_error& error)
    {
        cout << ERROR_COLOR << error.what() << RESET_COLOR << endl;
        cout << "Желаете зарегистрироваться?" << endl;
        cout << "1) Да \n" << "0) Нет" << endl;

        int action = Menu::getActionMenu(1);
        switch (action) {
            case 1:
                {
                    Tester* newTester = new Tester(login, password);
                    newTester->requestPersonalDetails();       
                    arrayUser.push_back(newTester);     
                    return newTester;
                }
            case 0:
                return nullptr;
        }
    }
}
