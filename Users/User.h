#pragma once
#include <iostream>
using namespace std;
#include <string>

typedef string s_t;    //  string ????? ?????? ??? s_t ??? ??????????

class IUser
{
public:
	virtual void Register() = 0;
	virtual void Login() = 0;
};


class User : public IUser
{
protected:
    s_t _login;
    s_t _password;
    s_t _role;

    User(s_t, s_t, s_t);
	bool authentication(s_t login, s_t pass);  //  <- TODO
public:

};
