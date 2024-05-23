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
