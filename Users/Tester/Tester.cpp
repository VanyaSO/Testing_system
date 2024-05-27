#include "Tester.h"
#include "../../common/config.h"
#include <algorithm>  // ��� all_of
#include <cctype>     // ��� isdigit

Tester::Tester()
	:_address(""),_phone(""), _fullName{"", "", ""}, User("", "", "tester")
{
}

Tester::Tester(string login, string pass)
	: _address(""), _phone(""), _fullName{ "", "", "" }, User(login, pass, "tester")
{
}

Tester::Tester(string login, string pass, string name, string sName, string lastName, string address, string phone)
    :_fullName{ name, sName, lastName }, _address(address), _phone(phone), User(login, pass, "tester")
{
}

string Tester::getFullName() const
{
	return _fullName.name + " " + _fullName.sName + " " + _fullName.lastName + " ";
}

string Tester::getAddress() const
{
	return _address;
}

string Tester::getPhone() const
{
	return _phone;
}


string Tester::getName() const
{
	return _fullName.name;
}

string Tester::getSname() const
{
	return _fullName.sName;
}

string Tester::getLastName() const
{
	return _fullName.lastName;
}

void Tester::setAddress(string address)
{
	_address = address;
}

void Tester::setPhone(string phone)
{
    if (all_of(phone.begin(), phone.end(), [](char c){ return isdigit(c);}))
	{
		_phone = phone;
	}
	else
	{
		throw invalid_argument("Номер телефона должен состоять из чисел");
	}
}

void Tester::changeAddress(string address)
{
	if (address.compare(_address) == 0)
	{
		throw logic_error("Новый адрес совпадает с текущим. Изменения невозможны.");
	}
	_address = address;
}

void Tester::changePhone(string phone)
{
	if (phone.compare(_phone) == 0)
	{
		throw logic_error("Новый номер телефона совпадает с текущим. Изменения невозможны.");
	}
	this->setPhone(phone);
}

void Tester::changeName(string name)
{
	if (name.compare(_fullName.name) == 0)
	{
		throw logic_error("Новое имя совпадает с текущим. Изменения невозможны.");
	}
	_fullName.name = name;
}

void Tester::changeSName(string sName)
{
	if (sName.compare(_fullName.sName) == 0)
	{
		throw logic_error("Новое отчество совпадает с текущим. Изменения невозможны.");
	}
	_fullName.sName = sName;
}

void Tester::changeLastName(string lastname)
{
	if (lastname.compare(_fullName.lastName) == 0)
	{
		throw logic_error("Новая фамилия совпадает с текущим. Изменения невозможны.");
	}
	_fullName.lastName = lastname;
}

void Tester::show()
{
    cout << "Логин: " << this->getLogin()  << endl;
    cout << "Пароль: " << this->getPassword()  << endl;
    cout << "ФИО: " << this->getFullName() << endl;
    cout << "Адрес: " << this->getAddress()  << endl;
    cout << "Телефон: " << this->getPhone()  << endl;
}

void Tester::Register()
{
	while (true)
	{
		cout << "Enter login: " << endl;
		cin >> _login;
		if (this->isUserRegistered())
		{
			cout<< ERROR_COLOR << "Пользователь уже существует" << RESET_COLOR << endl;
			continue;
		}
		break;
	}
	while (true)
	{
		cout << "Enter password: " << endl;
		cin >> _password;
		if (_password.length() < passMinSize) // passMinSize = 6 � config�
		{
			cout << ERROR_COLOR << "Пароль должен быть не менее 6 символов" << RESET_COLOR << endl;
			continue;
		}
		break;
	}
	try
	{
		requestPersonalDetails();
		arrayUser.push_back(this);
	}
	catch (const exception& err)
	{
		cout << ERROR_COLOR << "Ошибка: " << err.what() << RESET_COLOR << endl;
	}

}

void Tester::requestPersonalDetails()
{
	cout << "Enter name: " << endl;
	cin >> _fullName.name;
	cout << "Enter surname: " << endl;
	cin >> _fullName.sName;
	cout << "Enter lastname: " << endl;
	cin >> _fullName.lastName;
	cout << "Enter address: " << endl;
	cin >> _address;
	while (true)
	{
		cout << "Enter phone number: " << endl;
		cin >> _phone;
		if (all_of(_phone.begin(), _phone.end(), [](char c){ return isdigit(c);}))
		{
			break;
		}
		else
		{
			cout << ERROR_COLOR << "Номер телефона должен содержать только цифры." << RESET_COLOR << endl;
		}
	}
}

ostream& operator<<(ostream& out, Tester& tester) {
    out << "Логин: " << tester.getLogin()  << endl;
    out << "Пароль: " << tester.getPassword()  << endl;
    out << "ФИО: " << tester.getFullName() << endl;
    out << "Адрес: " << tester.getAddress()  << endl;
    out << "Телефон: " << tester.getPhone()  << endl;
}
