#include "TesterMenu.h"
#include "../../Users/Tester/Tester.h"

void TesterMenu::testerMenu() {
    cout << "1) Просмотреть свои результаты тестирования" << endl;
    cout << "2) Пройти новое тестирование" << endl;
    cout << "0) Вернуться назад" << endl;

    int action = getActionMenu(2);
    switch (action)
    {
        case 1:
            {
                cin.ignore();
                cout << "Просмотр" << endl;
                SaveResult results(path_to_results);
                results.readfFromFile();
                results.seeMyResults();
                break; 
            }
        case 2:
            {

                SaveResult results(path_to_results);
                Result myNewResult;
                myNewResult.setTesterLogin(user->getLogin());
                cout << "новое тестирование" << endl;
                TestManager pathToTest(path_to_test); //path_to_test
                FileWriteReadTest test;

                pathToTest.showFiles();
                cout << " Введите номер категории" << endl;
                action = getActionMenu(pathToTest.getDirSize(),1);
                system("cls");
                myNewResult.setTestCategory(pathToTest.getFileName(action));
                pathToTest.setNewPath(pathToTest.getFileName(action));
                pathToTest.scanExistingDirectories(); 
                if (pathToTest.getDirSize() ==0)
                {
                    cout << " Секции отсутствуют! обратитесь к админу!" << endl;
                    break;
                }
                else
                {

                    pathToTest.showFiles();
                    cout << " Введите номер секции" << endl;
                    action = getActionMenu(pathToTest.getDirSize(), 1);
                    system("cls");
                    pathToTest.setNewPath(pathToTest.getFileName(action));
                    pathToTest.scanExistingFiles();
                    if (pathToTest.getDirSize() == 0)
                    {
                        cout << " Тесты отсутствуют! обратитесь к админу!" << endl;
                        break;
                    }
                    else
                    {
                        pathToTest.showFiles();
                        cout << " Введите номер теста" << endl;
                        action = getActionMenu(pathToTest.getDirSize(), 1);
                        system("cls");
                        myNewResult.setTestName(pathToTest.getFileName(action));
                        test.setPathToTest(pathToTest.getPath()+"/"+pathToTest.getFileName(action));
                        cout << pathToTest.getPath() << endl;
                        cout << test.getPath() << endl;
                        test.readTest(myNewResult);
                        results.addResult(myNewResult);
                        results.writeToFile();
                        pathToTest.backToParent();// возврат в корневую директорию
                        break; 
                    }
                }

            }
        case 0:
            return;
    }

    testerMenu();
}
