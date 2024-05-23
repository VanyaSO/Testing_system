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
			fout << "CorrectAnswer:";
			fout << '\n';
			fout << Q.getNumOfCorrectAnswer();
			fout << '\n';
		}
		fout.close();
	}
}

void FileWriteReadTest::readTest()
{
	ifstream fin;
	string line;
	int numCorrectAnswer;
	fin.open(_pathToTest);
	if (!fin.is_open())
	{
		cout << "file not open!";
	}
	else
	{
		while (getline(fin, line)) 
		{
            if (line == "CorrectAnswer: ")
            {
                if (getline(fin, line))
                {
                    numCorrectAnswer = stoi(line);
                    //cout << numCorrectAnswer << endl;
                }
                // тут нужно запросить ответ у пользователя и сравнить его с indexCorrectAnswer
				system("cls");
            }
            else
            {
				
                cout << line << endl;
            }
		}
		fin.close();
	}
}
