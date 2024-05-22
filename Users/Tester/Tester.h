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
	Tester(string login,string pass);
	Tester(string login, string pass, string name, string sName, string lastName, string address, string phone);

	string getFullName() const;
	string getAddress() const;
	string getPhone() const;

	void setAddress(string address);
	void setPhone(string phone);  //   accept only digits  // add throw ?

	void show() override;		 // spriatat log & pass ?
	void Register() override;	 // добавить проверку длинны _phone ?
	void requestPersonalDetails();


	//void startTest();   // <- TODO
	//void watchResult();  // <- TODO
};