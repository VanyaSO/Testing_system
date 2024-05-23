#include "FileWriteReadUsers.h"
#include <iostream>
#include <fstream>
using namespace std;
#include "FileWriteReadUsers.h"
#include "../common/config.h"
#include "../Users/Admin/Admin.h"
#include "../Users/Tester/Tester.h"

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
    fstream fileTester;
    fileAdmin.open(path_file_admin, ios::binary | ios::out);
    fileTester.open(path_file_tester, ios::binary | ios::out);

    if (fileAdmin.is_open() && fileTester.is_open())
    {
        for (int i = 0; i < arrayUser.size(); ++i)
        {
            if (arrayUser[i]->getRole() == "admin")
            {
                writeStr(arrayUser[i]->getLogin(), fileAdmin);
                writeStr(arrayUser[i]->getPassword(), fileAdmin);
            }
            if (arrayUser[i]->getRole() == "tester")
            {
           
                Tester* tester = dynamic_cast<Tester*>(arrayUser[i]);
                writeStr(arrayUser[i]->getLogin(), fileTester);
                writeStr(arrayUser[i]->getPassword(), fileTester);
                //writeStr(dynamic_cast<Tester*>(arrayUser[i])->getName, fileTester);
                writeStr(tester->getName(), fileTester);
                writeStr(tester->getSname(), fileTester);
                writeStr(tester->getLastName(), fileTester);
                writeStr(tester->getAddress(), fileTester);
                writeStr(tester->getPhone(), fileTester);

            }
        }
        fileAdmin.close();
        fileTester.close();
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
