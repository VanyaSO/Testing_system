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

	void show() override;
	void Register() override;

	void changeTesterAddress(string login, string address);
	void changeTesterPhone(string login, string phone);
};
