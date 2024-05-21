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

	void show() override;
	void Register() override;	 // �������� �������� ������ _phone ?

	//void startTest();   // <- TODO
	//void watchResult();  // <- TODO
};