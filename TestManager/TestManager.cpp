#include "TestManager.h"

void TestManager::setNewPath(string path)
{
	//_parent_directory += "\\" + path;
	_parent_directory += "/" + path;
	//_parent_directory += path;
	this->scanExistingDirectories();
}

void TestManager::showFiles()
{
	for (int i = 0; i != _files.size(); i++)
	{
		cout << i + 1 << ") " << _files[i] << endl;
	};
}

void TestManager::backToParent()
{
	_parent_directory = _parent;
}

string TestManager::getPath()
{
	return _parent_directory.string();
}

string TestManager::getFileName(int index)
{
	return _files[index-1];// ����� ���������� ������ ��� �������
}

int TestManager::getDirSize()
{
	return _files.size();
}

TestManager::TestManager(const fs::path& parentDir) : _parent_directory(parentDir), _parent(parentDir)
{
	scanExistingDirectories(); // ������������ ������������ ���������� 
}

void TestManager::scanExistingDirectories()
{
	_files.clear();
	for (const auto& entry : fs::directory_iterator(_parent_directory))
	{
		if (entry.is_directory()) { // ��������, �������� �� ������� ������ �����������
			_files.push_back(entry.path().filename().string()); // ���������� ����� ���������� � ������
		}
	}
}

void TestManager::scanExistingFiles()
{
	_files.clear();
	for (const auto& entry : fs::directory_iterator(_parent_directory)) {
		if (fs::is_regular_file(entry.path())) // �������� �������� �� ������
		{
			_files.push_back(entry.path().filename().string()); //�����  ��� ����� � ������
		}
	}
}

bool TestManager::addDirectory(const string& dirName)
{
	fs::path dirPath = _parent_directory / dirName; // ������������ ������� ���� � ����������� ����������
	if (fs::exists(dirPath)) { // �������� �� ������������� ����������
		cout << "Directory already exists: " << dirPath << endl;
		return false; // �������������� �������� ����� ������� ����������
	}
	if (fs::create_directory(dirPath)) { // ������� ������� ����������
		_files.push_back(dirName); // ���������� ����� ���������� � ������
		cout << "Directory created and added: " << dirPath << endl;
		return true;
	}
	else {
		cout << "Failed to create directory: " << dirPath << endl;
		return false;
	}
}

bool TestManager::removeDirectory(int index)
{
	index--;
	fs::path dirPath = _parent_directory / _files[index]; // ������������ ������� ���� � ��������� ����������
	if (fs::remove_all(dirPath) > 0) { // ������� ������� ���������� � ��� �� ����������
		auto it = find(_files.begin(), _files.end(), _files[index]); // ����� ����� ���������� � �������
		if (it != _files.end()) {
			_files.erase(it); // �������� ����� ���������� �� �������
			cout << "Directory and its contents removed: " << dirPath << endl;
			return true;
		}
	}
	else {
		cout << "Failed to remove directory or it does not exist: " << dirPath << endl;
	}
	return false;
}
