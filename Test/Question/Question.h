#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Question
{
	string _question;
	vector<string> _answer;
	int _correctAnswer;
public:
	Question(); // ������ ������
	Question(string); // � ��������
	void setQuestion(string);  // ���������� ������
	void setCorrectAnswer(int);// ������ ������ ������� ������
	void addAnswerOption(string);// �������� ������� ������
	string getQuestion();  //�������� ������
	string getOneAnswer(int);  //�������� ����� �� �������
	string getCorrectAnswer();  // �������� ������ �����
	int getAnswerSize(); //������� ���������� �������
	int getNumOfCorrectAnswer(); //�������� ������ ����������� ������
	void showQuestion();  //������� ������ + ������

};
