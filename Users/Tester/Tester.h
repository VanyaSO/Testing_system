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

	void setAddress(string address);
	void setPhone(string phone); 
	void changeAddress(string address);
	void changePhone(string phone);
	void changeName(string name);
	void changeSName(string sName);
	void changeLastName(string lastname);

	void Register() override;	
	void requestPersonalDetails();
};

ostream& operator<<(ostream& out, Tester& tester);