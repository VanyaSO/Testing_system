#include "FileWriteReadTest.h"

void FileWriteReadTest::setPathToTest(string path)
{
	_pathToTest = path;
}

void FileWriteReadTest::saveTestToFile(Test& test)
{
	ofstream fout;
	fout.open(_pathToTest, ofstream::app);
	if (!fout.is_open())
	{
		cout << "file not open!";
	}
	else
	{
		fout << test.getTestName();
		fout << '\n';
		Question Q;
		for (int i = 0; i < test.getQuestionListSize(); i++)
		{
			Q = test.getQuestion(i);
			fout << Q.getQuestion();
			fout << '\n';
			for (int i = 0; i < Q.getAnswerSize(); i++)
			{
				fout << Q.getOneAnswer(i);
				fout << '\n';
			}
			fout << "CorrectAnswer: ";
			fout << '\n';
			fout << Q.getCorrectAnswer();
			fout << '\n';
		}
		fout.close();
	}
}

void FileWriteReadTest::readTest()
{
	ifstream fin;
	string line;
	int indexCorrectAnswer;
	fin.open(_pathToTest);
	if (!fin.is_open())
	{
		cout << "file not open!";
	}
	else
	{
		while (getline(fin, line)) // —читывание строки из файла
		{
			if (getline(fin, line))
			{
				indexCorrectAnswer = stoi(line);
				cout << sizeof(indexCorrectAnswer) << endl;
			}
			// тут нужно запросить ответ у пользовател€ и сравнить его с indexCorrectAnswer
			else
			{
				cout << line << endl;
			}
		}
		fin.close();
	}
}
