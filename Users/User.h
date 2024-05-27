#pragma once
#include <iostream>
using namespace std;
#include <string>

class IUser
{
public:
	virtual void Register() = 0;
};


class User : public IUser
{
    static int authentication(string login, string pass);
protected:
    string _login;
    string _password;
    string _role;

    User(string, string, string);
    bool isUserRegistered();
public:
    virtual ~User() {}

    string getLogin() const;
    string getPassword() const;
    string getRole() const;

    void changeLogin(string login);
    void changePassword(string password);

    static User* Login();
};
