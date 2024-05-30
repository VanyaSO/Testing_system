#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "../common/config.h"
#include "../../Users/Tester/Tester.h"
using namespace std;

class Result
{
    string _login;
    string _testCategory;
    string _testName;
    int _questionNum;
    int _correctAnswer;
    int _grade;
public:
    Result();
    Result(string, string,string, int, int, int);
    void showResults();
    string getTesterLogin();
    string getTestCategory();
    string getTestName();
    int getQuestionNum();
    int getCorrectAnswer();
    int getGrade();
    void setTesterLogin(string);
    void setTestCategory(string);
    void setTestName(string);
    void setQuestionNum(int);
    void setCorrectAnswer(int);
    void countGrade();
};