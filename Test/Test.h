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
	Test(); //пустой тест
	Test(string);// возможно не нужен
	void setTestName(string); // задать имя теста
	void addQuestion(string);// добавить вопрос
	void addAnswer(int, string);  // добавить ответ в вопрос по индексу
	int getQuestionListSize(); // получить количество вопросов
	string getTestName(); // получить имя теста
	Question getQuestion(int); // получить вопрос по индексу
	void showTest(); // распечатать весь тест с вопросами и ответами
};

