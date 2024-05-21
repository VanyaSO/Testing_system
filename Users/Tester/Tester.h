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
	Tester();
	Tester(string login, string pass, string name, string sName, string lastName, string address, string phone);

	string getFullName() const;
	string getAddress() const;
	string getPhone() const;

	void show() override;
	void Register() override;	 // добавить проверку длинны _phone ?

	//void startTest();   // <- TODO
	//void watchResult();  // <- TODO
};