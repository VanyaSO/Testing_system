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
	string getName() const;
	string getSname() const;
	string getLastName() const;
	string getLogin();

	void setAddress(string address);
	void setPhone(string phone); 
	void changeAddress(string address);
	void changePhone(string phone);
	void changeName(string name);
	void changeSname(string sName);
	void changeLastName(string lastname);


	void show() override;		
	void Register() override;	
	void requestPersonalDetails();


	//void startTest();   // <- TODO
	//void watchResult();  // <- TODO
};