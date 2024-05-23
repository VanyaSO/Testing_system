#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Question
{
	string _question;
	vector<string> _answer;
	int _correctAnswer;
public:
	Question(); // пустой вопрос
	Question(string); // с вопросом
	void setQuestion(string);  // установить вопрос
	void setCorrectAnswer(int);// задать индекс верного ответа
	void addAnswerOption(string);// добавить вариант ответа
	string getQuestion();  //получить вопрос
	string getOneAnswer(int);  //получить ответ по индексу
	string getCorrectAnswer();  // получить верный ответ
	int getAnswerSize(); //полуить количество ответов
	int getNumOfCorrectAnswer(); //получить индекс правильного ответа
	void showQuestion();  //вывести вопрос + ответы

};
