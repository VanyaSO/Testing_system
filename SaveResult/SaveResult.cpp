#include "SaveResult.h"

SaveResult::SaveResult(string path) :_filePath(path) {}

void SaveResult::addResult(Result res)
{
	_results.emplace_back(res);
}

void SaveResult::seeResultByName( string login)
{
	for (auto i = _results.begin(); i != _results.end(); i++)
	{
		if (login == (*i).getTesterLogin())
		{
			(*i).showResults();
		}
	}
}

void SaveResult::seeResultByTestName(string testName)
{
    for (auto i = _results.begin(); i != _results.end(); i++)
    {
        if ((testName+".txt") == (*i).getTestName())
        {
            (*i).showResults();
        }
    }
}

void SaveResult::seeResultByCategory(string category)
{
    for (auto i = _results.begin(); i != _results.end(); i++)
    {
        if (category == (*i).getTestCategory())
        {
            (*i).showResults();
        }
    }
}

void SaveResult::seeMyResults()
{
	for (auto i = _results.begin(); i != _results.end(); i++)
	{
		if (user->getLogin() == (*i).getTesterLogin())
		{
			(*i).showResults();
		}
	}
}

void SaveResult::writeToFile()
{
    ofstream fout;
    fout.open(_filePath, ofstream::app);  //дозаписать файл
    if (!fout.is_open()) 
    {
        cout << "Файл не открылся!";
    }
    else
    {
        for (auto i = _results.begin(); i != _results.end(); i++)
        {
            fout << ((*i).getTesterLogin());
            fout << '\n';
            fout << ((*i).getTestCategory());
            fout << '\n';
            fout << ((*i).getTestName());
            fout << '\n';
            fout << ((*i).getQuestionNum());
            fout << '\n';
            fout << ((*i).getCorrectAnswer());
            fout << '\n';
            fout << ((*i).getGrade());
            fout << '\n';
        }
        fout.close();
    }
}
void SaveResult::readfFromFile()
{
    ifstream fin;
    fin.open(_filePath);
    if (!fin.is_open())
    {
        cout << "Файл не відкрився!";
    }
    else
    {
        string str;
        while (!fin.eof())
        { 
            string login;
            string testCategory;
            string testName;
            int questionNum;
            int correctAnswer;
            int grade;
            if (!getline(fin, login)) break;
            if (!getline(fin, testCategory)) break;
            if (!getline(fin, testName)) break;
            if (!(fin >> questionNum)) break;
            if (!(fin >> correctAnswer)) break;
            if (!(fin >> grade)) break;
            fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            _results.emplace_back(login, testCategory, testName, questionNum, correctAnswer,grade);
            
        }
        fin.close();

    }
}