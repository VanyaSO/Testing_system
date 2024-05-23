#pragma once
#include <filesystem>   // Подключение библиотеки для работы с файловой системой
#include <vector>       // Подключение библиотеки для работы с векторами
#include <string>       // Подключение библиотеки для работы со строками
#include <iostream>     // Подключение библиотеки для вывода на консоль
using namespace std;

namespace fs = filesystem; // Использование пространства имен для упрощения записи

class TestManager
{
    fs::path _parent_directory; // Путь к родительской директории
    const fs::path _parent; // Путь к родительской директории
    vector<string> _files; // Вектор для хранения имен директорий

public:
    // Конструктор, принимающий путь к родительской директории
    TestManager(const fs::path&);
    // Метод для сканирования существующих директорий и записи их в массив
    void scanExistingDirectories();
    // Метод для сканирования существующих файлов и запись их в массив
    void scanExistingFiles();
    // Метод для добавления директории и записи ее имени в вектор
    bool addDirectory(const string&);
    // Метод для удаления директории и удаления ее имени из вектора
    bool removeDirectory(int index);
    //установить новый путь старый + имя папки
    void setNewPath(string);
    //показать папки или файлы в текущай директории
    void showFiles();
    // вернуться в корневую папку
    void backToParent();
    // получить путь текущей папки
    string getPath();
    //получить имя папки или файла с массива по индексу
    string getFileName(int);
    //получить количество элементов в массиве
    int getDirSize();
};
