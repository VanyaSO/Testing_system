#pragma once

#include "../User.h"


class Admin : public User
{

public:
	Admin(string login, string pass, string role);

	void show();  //  ����� ������ show � ������?
	void Register();  // <- TODO
	void Login();	// <- TODO
};
