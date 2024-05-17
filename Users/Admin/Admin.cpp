#include "Admin.h"

Admin::Admin(string login, string pass, string role)
{
	_login = login;
	_password = pass;
	_role = role;
}

void Admin::show()
{
	cout << "Admin Login: " << _login << "\n" << "Admin Passw: " << _password << "\n" << "Admin Role: " << _role << endl << endl;
}

void Admin::Register()
{
	// TODO
}

void Admin::Login()
{
	// TODO
}
