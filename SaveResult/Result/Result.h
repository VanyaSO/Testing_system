#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../config.h"
#include "Tester/Tester.h"
using namespace std;

class Result
{
    string _login;
    string _testName;
    int _grade;
public:
    Result(string, string, int);
    Result(string,int ,int);
    void showResults();
    string getTesterLogin();
    string getTestName();
    int getGrade();
};
