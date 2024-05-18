#pragma once
#include "../User.h"


class Admin : public User
{

public:
	Admin(s_t login, s_t pass):User(login, pass, "admin"){}

	void show();  //  ����� ������ show � ������?
	void Register();  // <- TODO
	void Login();	// <- TODO
};
