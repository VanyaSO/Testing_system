#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "Question/Question.h"


class Test
{
	string _testName;
	vector<Question> _questionList;
public:
	Test();
	Test(string);
	void setTestName(string);
	void addQuestion(string);
	void addAnswer(string);
	void addCorrectAnswer(int);
	int getQuestionListSize();
	string getTestName();
	Question& getQuestion(int);
	void showTest();
};

