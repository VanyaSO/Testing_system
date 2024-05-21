#pragma once
#include <vector>
#include "../User.h"

class Admin : public User
{

public:
    Admin():User("", "", "admin"){}
	Admin(string login, string pass):User(login, pass, "admin"){}

	void show() override;
	void Register() override;
};
