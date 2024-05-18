#include "Test.h"

Test::Test()
{
}

Test::Test(string testName)
{
	_testName = testName;
}

void Test::setTestName(string testName)
{
	_testName = testName;
}

void Test::addQuestion(string question)
{
	_questionList.emplace_back(question);
}

void Test::addAnswer(int index, string answer)
{
	_questionList[index].addAnswerOption(answer);
}

int Test::getQuestionListSize()
{
	return _questionList.size();
}

string Test::getTestName()
{
	return _testName;
}

Question Test::getQuestion(int index)
{
	return _questionList[index];
}


void Test::showTest()
{
	for (int i = 0; i < _questionList.size(); i++) {
		_questionList[i].showQuestion();
	}
}

