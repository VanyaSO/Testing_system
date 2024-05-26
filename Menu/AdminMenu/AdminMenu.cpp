#include "AdminMenu.h"
#include "../../common/config.h"
#include "../../Users/Tester/Tester.h"

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
        {
            string newLogin;
            cout << "Ввдите новый логин" << endl;
            cin >> newLogin;

            try
            {
                user->changeLogin(newLogin);
                cout << SUCCESSFUL_COLOR << "Логин успешно изменен" << RESET_COLOR << endl;
            }
            catch (const logic_error& error)
            {
                cout << ERROR_COLOR << error.what() << RESET_COLOR << endl;
            }
            break;
        }
        case 2:
        {
            string newLogin;
            cout << "Ввдите новый пароль" << endl;
            cin >> newLogin;

            try
            {
                user->changePassword(newLogin);
                cout << SUCCESSFUL_COLOR << "Пароль успешно изменен" << RESET_COLOR << endl;
            }
            catch (const logic_error& error)
            {
                cout << ERROR_COLOR << error.what() << RESET_COLOR << endl;
            }
            break;
        }
        case 3:
            AdminMenu::adminMenuUserManagement();
            break;
        case 4:
            AdminMenu::adminMenuStatistics();
            break;
        case 5:
            AdminMenu::adminMenuTestManagement();
            break;
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
        {
            Tester* newTester = new Tester();
            newTester->Register();
            arrayUser.push_back(newTester);
            break;
        }
        case 2:
        {
            string userLogin;
            string adminPassword;
            cout << "Введите логин пользователя" << endl;
            cin >> userLogin;

            auto deleteUser = find_if(arrayUser.begin(), arrayUser.end(), [&userLogin](User*& obj) {
                return obj->getLogin() == userLogin;
            });

            if (deleteUser == arrayUser.end())
            {
                cout << ERROR_COLOR << "Пользователя не сущесвует" << RESET_COLOR << endl;
                break;
            }

            cout << WARNING_COLOR << "Введите пароль для подтвержения" << RESET_COLOR << endl;
            cin >> adminPassword;
            if (adminPassword != user->getPassword())
            {
                cout << ERROR_COLOR << "Пароль неверный !" << RESET_COLOR << endl;
                break;
            }
            arrayUser.erase(deleteUser);
            cout << SUCCESSFUL_COLOR << "Пользователь успешно удален" << RESET_COLOR << endl;
            break;
        }
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
    cout << "2) Просмотр категорий" << endl;
    cout << "3) Добавить секцию" << endl;
    cout << "4) Просмотр секций" << endl;
    cout << "5) Добавить тест" << endl;
    cout << "6) Просмотр тестов" << endl;
    cout << "0) Вернуться назад" << endl;
    TestManager pathToTest("../data/dataTest");
    FileWriteReadTest test;
    int action = getActionMenu(6);

    switch (action)
    {
        case 1:
        {
            cout << "Добавить категорию" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string categoryName;
            cout << "Введите имя новой категории!" << endl;
            getline(cin, categoryName);
            pathToTest.addDirectory(categoryName);
            break;
        }
        case 2:
        {
            pathToTest.showFiles();
            break;
        }
        case 3:
        {
            cout << "Добавить секцию" << endl;
            pathToTest.showFiles();
            cout << "Введите номер категории, где нужно добавить секцию" << endl;
            action = getActionMenu(pathToTest.getDirSize(), 1);// запрос в какую категорию ! 
            pathToTest.setNewPath(pathToTest.getFileName(action));
            string sectionName;
            cout << "Введите имя новой секции!" << endl;
            getline(cin, sectionName);
            pathToTest.addDirectory(sectionName);
            pathToTest.backToParent();
            system("cls");
            break;
        }
        case 4:
        {
            pathToTest.showFiles();
            cout << "Введите номер категории, для просмотра секций" << endl;
            action = getActionMenu(pathToTest.getDirSize(), 1); 
            pathToTest.setNewPath(pathToTest.getFileName(action));
            if (pathToTest.getDirSize()==0)
            {
                system("cls");
                cout << "Данная категория пока пуста" << endl;
                break;
            }
            else
                pathToTest.showFiles();
            break;
        }
        case 5:
        {

            cout << "Добавить тест" << endl;
            pathToTest.showFiles();
            cout << " Введите номер категории" << endl;
            action = getActionMenu(pathToTest.getDirSize(), 1);
            pathToTest.setNewPath(pathToTest.getFileName(action));
            pathToTest.scanExistingDirectories();
            system("cls");
            if (pathToTest.getDirSize() == 0)
            {
                cout << "Данная категорияпутса! добавьте секцию!" << endl;
                break;
            }
            else
            {
                pathToTest.showFiles();
                cout << " Введите номер секции" << endl;
                action = getActionMenu(pathToTest.getDirSize(), 1);
                pathToTest.setNewPath(pathToTest.getFileName(action));
                pathToTest.scanExistingFiles();
                system("cls");
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << " Введите имя нового теста" << endl;
                string testName;
                getline(cin, testName);
                Test newTest(testName);
                bool addQuestion = true;
                int count = -1;
                while (addQuestion)
                {
                    cout << "1) Добавить вопрос" << endl;
                    cout << "2) завершить" << endl;
                    action = getActionMenu(2, 1);
                    switch (action)
                    {
                    case 1:
                    {
                        count++;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Введите вопрос!" << endl;
                        string question;
                        getline(cin, question);
                        newTest.addQuestion(question);
                        bool addAnswer = true;
                        while (addAnswer)
                        {
                            cin.ignore(1, '\n');
                            cout << "Введите вариант ответа (или нажмите Enter чтобы завершить)" << endl;
                            string answer;
                            getline(cin, answer);
                            if (answer != "")
                            {
                                newTest.addAnswer(answer);
                            }
                            else
                            {
                                newTest.getQuestion(count).showQuestion();
                                cout << "Введите номер правильного ответа" << endl;
                                action = getActionMenu(newTest.getQuestion(count).getAnswerSize(), 1);
                                newTest.addCorrectAnswer(action - 1);
                                addAnswer = false;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        addQuestion = false;
                        break;
                    }
                    }
                }

            if (newTest.getQuestionListSize() != 0)
            {
                test.setPathToTest(pathToTest.getPath() + "/" + newTest.getTestName() + ".txt");
                test.saveTestToFile(newTest);
                pathToTest.backToParent();
            }
            }
            break;
        }
        case 6:
        {
            pathToTest.showFiles();
            cout << "Введите номер категории, для просмотра секций" << endl;
            action = getActionMenu(pathToTest.getDirSize(), 1);
            pathToTest.setNewPath(pathToTest.getFileName(action));
            if (pathToTest.getDirSize() == 0)
            {
                cout << "Данная категория пока пуста" << endl;
                break;
            }
            else
            {
                pathToTest.showFiles();
                cout << " Введите номер секции, для просмотра тестов" << endl;
                action = getActionMenu(pathToTest.getDirSize(), 1);// запрос какую категорию??? по номеру! 
                pathToTest.setNewPath(pathToTest.getFileName(action));
                pathToTest.scanExistingFiles(); // сканируем доступные
                system("cls");
                if (pathToTest.getDirSize() == 0)
                {
                    cout << "Данная секция пока пуста" << endl;
                    break;
                }
                else
                {
                    cout << " Доступные тесты:" << endl;
                    pathToTest.showFiles();
                    pathToTest.backToParent();
                }
            }
            break;
        }
        case 0:
            return;
    }
    adminMenuTestManagement();
}