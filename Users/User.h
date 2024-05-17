#pragma once
#include <iostream>
using namespace std;
#include <string>

typedef string s_t;    //  string ����� ������ ��� s_t ��� ����������

class IUser
{
public:
	virtual void Register() = 0;
	virtual void Login() = 0;
};



class User : public IUser
{
protected:
	string _login;
	string _password;
	string _role;

	bool authentication(string login, string pass);  //  <- TODO
public:

};
