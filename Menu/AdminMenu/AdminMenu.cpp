#include "AdminMenu.h"
void AdminMenu::adminMenu()
{
    cout << "Главное меню" << endl;
    cout << "1) Изменить логин" << endl;
    cout << "2) Изменить пароль" << endl;
    cout << "3) Управление пользователями" << endl;
    cout << "4) Просмотр статистики" << endl;
    cout << "5) Управление тестами" << endl;
    cout << "0) Выйти" << endl;

    int action = getActionMenu(5);

    switch (action)
    {
        case 1:
            cout << "Замена логина" << endl;
            break; //TODO: замена логина
        case 2:
            cout << "Замена пароля" << endl;
            break; //TODO: замена пароля
        case 3:
            AdminMenu::adminMenuUserManagement();
            break;
        case 4:
            AdminMenu::adminMenuStatistics();
            break; //TODO: меню Просмотр. статистики
        case 5:
            AdminMenu::adminMenuTestManagement();
            break; //TODO: меню упр. тестами
        case 0:
            return;
    }

    adminMenu();
}

void AdminMenu::adminMenuUserManagement()
{
    cout << "Меню управление пользователями" << endl;
    cout << "1) Зарегистрировать пользователя" << endl;
    cout << "2) Удалить пользователя" << endl;
    cout << "3) Модифицировать данные пользователя" << endl;
    cout << "0) Вернуться назад" << endl;

    int action = getActionMenu(3);

    switch (action)
    {
        case 1:
            cout << "Рег. пользователя" << endl;
            break; //TODO: рег.
        case 2:
            cout << "Удаляем пользователя" << endl;
            break; //TODO: Удалить пользователя
        case 3:
            cout << "Модифицировать данные пользователя" << endl;
            break; //TODO: Модифицировать данные пользователя
        case 0:
            return;
    }

    adminMenuUserManagement();
}

void AdminMenu::adminMenuStatistics()
{
    cout << "Меню просмотра результатов тестирования" << endl;
    cout << "1) По категориям" << endl; //TODO: функция для просмотра статичтики в конкретном тесте
    cout << "2) По конкретныму тесту" << endl; //TODO: функция для просмотра статистики в конкретном тесте
    cout << "3) За конкретными пользователями" << endl; //TODO: функция для просмотра статистики по конк. пользователю
    cout << "0) Вернуться назад" << endl;

    int action = getActionMenu(3);

    switch (action)
    {
        case 1:
            cout << "По категориям" << endl;
            break; //TODO: По категориям
        case 2:
            cout << "По конкретныму тесту" << endl;
            break; //TODO: По конкретныму тесту
        case 3:
            cout << "За конкретными пользователями" << endl;
            break; //TODO: За конкретными пользователями
        case 0:
            return;
    }

    adminMenuStatistics();
}

void AdminMenu::adminMenuTestManagement()
{
    cout << "Меню управления тестами" << endl;
    cout << "1) Добавить категорию" << endl;
    cout << "2) Добавить тест" << endl;
    cout << "3) Добавить вопрос" << endl;
    cout << "4) Задавать правильные и неправильные ответы" << endl;
    cout << "5) Импортировать категории и тесты с вопросами из файла" << endl;
    cout << "6) Экспортировать категории и тесты с вопросами в файл" << endl;
    cout << "0) Вернуться назад" << endl;

    int action = getActionMenu(6);

    switch (action)
    {
        case 1:
            cout << "Добавить категорию" << endl;
            break; //TODO: создание категории
        case 2:
            cout << "Добавить тест" << endl;
            break; //TODO: создание теста
        case 3:
            cout << "Добавить вопрос" << endl;
            break; //TODO: создание вопрос
        case 4:
            cout << "Задавать правильные и неправильные ответы" << endl;
            break; //TODO: Задавать правильные и неправильные ответы
        case 5:
            cout << "Импортировать категории и тесты с вопросами из файла" << endl;
            break; //TODO: Импортировать категории и тесты с вопросами из файла
        case 6:
            cout << "Экспортировать категории и тесты с вопросами в файл" << endl;
            break; //TODO: Экспортировать категории и тесты с вопросами в файла
        case 0:
            return;
    }
    adminMenuTestManagement();
}