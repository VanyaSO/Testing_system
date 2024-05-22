#include <iostream>
#include <fstream>
using namespace std;
#include "FileWriteReadUsers.h"
#include "../common/config.h"
#include "../Users/Admin/Admin.h"

void FileWriteReadUsers::writeStr(string str, fstream& file)
{
    size_t size = str.size();
    // записываем длину строки
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    // записываем саму строку
    file.write(str.c_str(), size);
}

string FileWriteReadUsers::readStr(fstream& file)
{
    size_t size;
    if (!file.read(reinterpret_cast<char*>(&size), sizeof(size))) { return "null"; }
    char* temp = new char[size + 1];
    file.read(temp, size);
    temp[size] = '\0';
    string str(temp);
    delete[] temp;

    return str;
}

void FileWriteReadUsers::saveUsersToFile()
{
    if (arrayUser.empty()) return;

    fstream fileAdmin;
    fileAdmin.open(path_file_admin, ios::binary | ios::out);

    if (fileAdmin.is_open())
    {
        for (int i = 0; i < arrayUser.size(); ++i)
        {
            if (arrayUser[i]->getRole() == "admin")
            {
                writeStr(arrayUser[i]->getLogin(), fileAdmin);
                writeStr(arrayUser[i]->getPassword(), fileAdmin);
            }
        }
        fileAdmin.close();
    }
}

void FileWriteReadUsers::loadUsersFromFile()
{
    fstream fileAdmin;
    fileAdmin.open(path_file_admin, ios::binary | ios::in);

    if (fileAdmin.is_open())
    {
        while(true)
        {
            string login(readStr(fileAdmin));
            if (login == "null")
            { break; }
            string password(readStr(fileAdmin));

            arrayUser.push_back(new Admin(login, password));
        }
        fileAdmin.close();
    }
}