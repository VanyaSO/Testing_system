#include "Tester.h"

Tester::Tester(string login, string pass, string name, string sName, string lastName, string address, string phone)
    :_fullName{ name, sName, lastName }, _address(address), _phone(phone), User(login, pass, "tester")
{
}

void Tester::show()
{
	cout << _fullName.name << " " << _fullName.sName << " " << _fullName.lastName << endl;
	cout << _role << " " << _address << " " << _phone << endl;
	cout << "Login: " << _login << " " << "Password: " << _password << endl << endl;
}

void Tester::Register()
{
	// TODO
}
