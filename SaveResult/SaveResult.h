#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Result/Result.h"
using namespace std;

class SaveResult
{
    string _filePath;
    vector<Result> _results;
public:
    SaveResult(string);
    void addResult(Result);
    void seeResultByName(string);
    void seeMyResults();
    void writeToFile();
    void readfFromFile()
};