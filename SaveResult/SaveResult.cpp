#include "SaveResult.h"

SaveResult::SaveResult()
{
}

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
