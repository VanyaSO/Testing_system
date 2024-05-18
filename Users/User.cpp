#include "User.h"

User::User(string login, string pass, string role)
{
    _login = login;
    _password = pass;
    _role = role;
}

bool User::authentication(string login, string pass)
{
    return false;   // TODO: 
}
