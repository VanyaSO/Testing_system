#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Result/Result.h"
#include <fstream>
#include "../common/config.h"
using namespace std;

class SaveResult
{
    string _filePath;
    vector<Result> _results;
public:
    SaveResult(string);
    void addResult(Result);
    void seeResultByName(string);
    void seeResultByTestName(string);
    void seeResultByCategory(string);
    void seeMyResults();
    void writeToFile();
    void readfFromFile();
};