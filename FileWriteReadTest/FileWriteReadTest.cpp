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
		int answer;// временно
		while (getline(fin, line)) 
		{
            if (line == "CorrectAnswer:")
            {
                if (getline(fin, line))
                {
                    numCorrectAnswer = stoi(line);
                    // ВРЕМЕННООООООО!!!!!!!!!!!!!!ТУТ МОГЛА БЫТЬ ВАША РЕКЛАМА!!!
					cout << " Введите номер правильного ответа!" << endl;
					cin >> answer;
					if (answer ==numCorrectAnswer)
					{
						cout << "Верно ты молодец" << endl;
					}
					else
						cout << "OPSSSSS" << endl;
					// ДО СЮДА ВРЕМЕННООООООО!!!!!!!!!!!!!!
                }
                
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

string FileWriteReadTest::getPath()
{
	return _pathToTest;
}
