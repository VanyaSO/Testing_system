#include "Question.h"

Question::Question() : _correctAnswer(0) {}

Question::Question(string question) : _question(question), _correctAnswer(0) {}

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
	_correctAnswer = correctAnswer+1;
}

void Question::addAnswerOption(string answer)
{
	_answer.push_back(answer);
}

string Question::getCorrectAnswer()
{
	return _answer[_correctAnswer];
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

static int _questionIndex = 0;