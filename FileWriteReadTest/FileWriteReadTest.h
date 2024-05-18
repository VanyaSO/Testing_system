#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include "../Test/Test.h"
#include "../Test/Question/Question.h"

class FileWriteReadTest
{
	string _pathToTest;
public:
	void setPathToTest(string);
	void saveTestToFile(Test&);
	void readTest();

};