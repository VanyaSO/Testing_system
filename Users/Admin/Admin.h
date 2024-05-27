#pragma once
#include <utility>
#include <vector>
#include "../User.h"
#include "../Tester/Tester.h"

class Admin : public User
{

public:
    Admin():User("", "", "admin"){}
	Admin(string login, string pass):User(login, pass, "admin"){}

	void Register() override;

	void changeTesterAddress(Tester* tester, string address);
	void changeTesterPhone(Tester* tester, string phone);
	void changeTesterName(Tester* tester, string name);
	void changeTesterSname(Tester* tester, string sName);
	void changeTesterLastName(Tester* tester, string lastName);
};

ostream& operator<<(ostream& out, Admin& admin);
