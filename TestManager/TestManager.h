#pragma once
#include <filesystem>   // ����������� ���������� ��� ������ � �������� ��������
#include <vector>       // ����������� ���������� ��� ������ � ���������
#include <string>       // ����������� ���������� ��� ������ �� ��������
#include <iostream>     // ����������� ���������� ��� ������ �� �������
using namespace std;

namespace fs = filesystem; // ������������� ������������ ���� ��� ��������� ������

class TestManager
{
    fs::path _parent_directory; // ���� � ������������ ����������
    const fs::path _parent; // ���� � ������������ ����������
    vector<string> _files; // ������ ��� �������� ���� ����������

public:
    // �����������, ����������� ���� � ������������ ����������
    TestManager(const fs::path&);
    // ����� ��� ������������ ������������ ���������� � ������ �� � ������
    void scanExistingDirectories();
    // ����� ��� ������������ ������������ ������ � ������ �� � ������
    void scanExistingFiles();
    // ����� ��� ���������� ���������� � ������ �� ����� � ������
    bool addDirectory(const string&);
    // ����� ��� �������� ���������� � �������� �� ����� �� �������
    bool removeDirectory(int index);
    //���������� ����� ���� ������ + ��� �����
    void setNewPath(string);
    //�������� ����� ��� ����� � ������� ����������
    void showFiles();
    // ��������� � �������� �����
    void backToParent();
    // �������� ���� ������� �����
    string getPath();
    //�������� ��� ����� ��� ����� � ������� �� �������
    string getFileName(int);
    //�������� ���������� ��������� � �������
    int getDirSize();
};
