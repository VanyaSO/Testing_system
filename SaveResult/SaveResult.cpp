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
		if (login == (*i).getTesterLogin)
		{
			(*i).showResults();
		}
	}
}

void SaveResult::seeMyResults()
{
	for (auto i = _results.begin(); i != _results.end(); i++)
	{
		if (user->getLogin() == (*i).getTesterLogin)
		{
			(*i).showResults();
		}
	}
}

void SaveResult::writeToFile()
{
    ofstream fout;
    fout.open(concatPath(), ofstream::app);  //���������� ����
    if (!fout.is_open()) 
    {
        cout << "���� �� ��������!";
    }
    else
    {
        for (auto i = _results.begin(); i != _results.end(); i++)
        {
            fout << (*i).getTesterLogin();
            fout << '\n';
            fout << (*i).getTestName();
            fout << '\n';
            fout << (*i).getGrade();
            fout << '\n';
         
        }
        fout.close();
    }
}
void SaveResult::readfFromFile()
{
    ifstream fin;
    fin.open(concatPath());
    if (!fin.is_open())
    {
        cout << "���� �� ��������!";
    }
    else
    {
        string str;
        while (!fin.eof())
        {
            str = ""; //��� �� ������������ ���������� ����� � ������
            fin >> str;
            cout << str << endl;
        }

    }
}