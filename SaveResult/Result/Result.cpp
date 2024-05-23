#include "Result.h"

Result::Result(string login, string _testName, int grade) : _login(login), _testName(testName), _grade(grade) {}

Result::Result(string testName, int questions, int correctAns)
{
	_login = user->getLogin;
	_testName = testName;
	_grade = 12 / questions * correctAns;
}

void Result::showResults()
{
	for (User* us : user) {
		if (Tester* tester = dynamic_cast<Tester*>(us)) 
		{
			if (tester->getLogin == _login)
			{
				cout << "Пользователь: "<< tester->getFullName << end;
				cout << "Тест: " << _testName;
				cout << "Оценка: " << _grade;
			}
		}
	}
}

string Result::getTesterLogin()
{
	return _login;
}

string Result::getTestName()
{
	return _testName;
}

int Result::getGrade()
{
	return _grade;
}

