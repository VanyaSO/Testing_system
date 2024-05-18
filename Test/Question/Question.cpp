#include "Question.h"

Question::Question() {}

Question::Question(string question) : _question(question) {}

void Question::setQuestion(string question)
{
	_question = question;
}

string Question::getQuestion()
{
	return _question;
}

string Question::getOneAnswer(int index)
{
	return _answer[index];
}

void Question::setCorrectAnswer(int correctAnswer)
{
	_correctAnswer = correctAnswer;
}

void Question::addAnswerOption(string answer)
{
	_answer.push_back(answer);
}

string Question::getCorrectAnswer()
{
	//return _answer[_correctAnswer];
	return _answer[0]; //времено для проверки
}

int Question::getAnswerSize()
{
	return _answer.size();
}

int Question::getNumOfCorrectAnswer()
{
	return _correctAnswer;
}

void Question::showQuestion()
{
	cout << "Question: " << _question << endl;
	for (int i = 0; i < _answer.size(); i++)
	{
		cout << i + 1 << ") " << _answer[i] << endl;
	}
}

