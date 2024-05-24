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
	return _files[index-1];// можно обработать ошибку вне радиуса
}

int TestManager::getDirSize()
{
	return _files.size();
}

TestManager::TestManager(const fs::path& parentDir) : _parent_directory(parentDir), _parent(parentDir)
{
	scanExistingDirectories(); // —канирование существующих директорий 
}

void TestManager::scanExistingDirectories()
{
	_files.clear();
	for (const auto& entry : fs::directory_iterator(_parent_directory))
	{
		if (entry.is_directory()) { // ѕроверка, €вл€етс€ ли текуща€ запись директорией
			_files.push_back(entry.path().filename().string()); // ƒобавление имени директории в вектор
		}
	}
}

void TestManager::scanExistingFiles()
{
	_files.clear();
	for (const auto& entry : fs::directory_iterator(_parent_directory)) {
		if (fs::is_regular_file(entry.path())) // проверка €вл€етс€ ли файлом
		{
			_files.push_back(entry.path().filename().string()); //пушим  им€ файла в массив
		}
	}
}

bool TestManager::addDirectory(const string& dirName)
{
	fs::path dirPath = _parent_directory / dirName; // ‘ормирование полного пути к создаваемой директории
	if (fs::exists(dirPath)) { // ѕроверка на существование директории
		cout << "Directory already exists: " << dirPath << endl;
		return false; // еслисуществует возможно нужно ексепшн отработать
	}
	if (fs::create_directory(dirPath)) { // ѕопытка создать директорию
		_files.push_back(dirName); // ƒобавление имени директории в вектор
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
	fs::path dirPath = _parent_directory / _files[index]; // ‘ормирование полного пути к удал€емой директории
	if (fs::remove_all(dirPath) > 0) { // ѕопытка удалить директорию и все ее содержимое
		auto it = find(_files.begin(), _files.end(), _files[index]); // ѕоиск имени директории в векторе
		if (it != _files.end()) {
			_files.erase(it); // ”даление имени директории из вектора
			cout << "Directory and its contents removed: " << dirPath << endl;
			return true;
		}
	}
	else {
		cout << "Failed to remove directory or it does not exist: " << dirPath << endl;
	}
	return false;
}
