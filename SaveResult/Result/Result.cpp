#include "Result.h"


Result::Result() {}

Result::Result(string login, string testCategory, string testName, int questionNum, int correctAnswer, int grade)
	: _login(login), _testCategory(testCategory), _testName(testName), _questionNum(questionNum), _correctAnswer(correctAnswer), _grade(grade) {}

void Result::showResults()
{
	cout << "������������: "<< _login << endl;
	cout << "���������: " << _testCategory << endl;
	cout << "����: " << _testName<<endl;
	cout << "���������� ��������: " << _questionNum<<endl;
	cout << "���������� ���������� �������: " << _correctAnswer<<endl;
	cout << "������: " << _grade<<endl;

}

string Result::getTesterLogin()
{
	return _login;
}

string Result::getTestCategory()
{
	return _testCategory;
}

string Result::getTestName()
{
	return _testName;
}

int Result::getQuestionNum()
{
	return _questionNum;
}

int Result::getCorrectAnswer()
{
	return _correctAnswer;
}

int Result::getGrade()
{
	return _grade;
}

void Result::setTesterLogin(string login)
{
	_login = login;
}

void Result::setTestCategory(string category)
{
	_testCategory = category;
}

void Result::setTestName(string testName)
{
	_testName = testName;
}

void Result::setQuestionNum(int questionNu)
{
	_questionNum = questionNu;
}

void Result::setCorrectAnswer(int correctAnswer )
{
	_correctAnswer = correctAnswer;
}

void Result::countGrade()
{
	_grade = (12 / _questionNum) * _correctAnswer;
}

