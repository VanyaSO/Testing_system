#include "Tester.h"

//Tester::Tester (s_t login, s_t pass, s_t role, s_t name, s_t sName, s_t lastName, s_t address, s_t phone)
//	: User(login,pass,role),_fullName{name,sName,lastName},_address(address),_phone(phone){}

Tester::Tester(s_t login, s_t pass, s_t name, s_t sName, s_t lastName, s_t address, s_t phone)
    :_fullName{ name, sName, lastName }, _address(address), _phone(phone), User(login, pass, "tester")
{
	_address = address;
	_phone = phone;
}


void Tester::show()
{
	cout << _fullName.name << " " << _fullName.sName << " " << _fullName.lastName << endl;
	cout << _role << " " << _address << " " << _phone << endl;
	cout << "Login: " << _login << " " << "Password: " << _password << endl << endl;   // login, pass  ����� �������� !?!
}

void Tester::Register()
{
	// TODO
}

void Tester::Login()
{
	// TODO
}
