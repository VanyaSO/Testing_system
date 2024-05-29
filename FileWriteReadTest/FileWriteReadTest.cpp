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

void FileWriteReadTest::readTest(Result& myResult)
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
		int answer,answerNum = 0,correctAnswer = 0;// временно
		while (getline(fin, line)) 
		{
            if (line == "CorrectAnswer:")
            {
                if (getline(fin, line))
                {
                    numCorrectAnswer = stoi(line);
					cout << " Введите номер правильного ответа!" << endl;
					cin >> answer;
					answerNum++;
					if (answer ==numCorrectAnswer)
					{
						correctAnswer++;
					}
                }
                
				system("cls");
            }
            else
            {
				
                cout << line << endl;
            }
		}
		myResult.setQuestionNum(answerNum);
		myResult.setCorrectAnswer(correctAnswer);
		myResult.countGrade();
		fin.close();
	}
}

string FileWriteReadTest::getPath()
{
	return _pathToTest;
}
