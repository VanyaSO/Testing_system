#pragma once
#include "../User.h"

struct FullName
{
	string name;
	string sName;
	string lastName;
};


class Tester : public User
{
	FullName _fullName;
	string _address;
	string _phone;
public:
	Tester(s_t login, s_t pass, s_t name, s_t sName, s_t lastName, s_t address, s_t phone);

	void show();
	void Register();		// <- TODO  {}
	void Login();		// <- TODO
	//void startTest();   // <- TODO
	//void watchResult();  // <- TODO

};