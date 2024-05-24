#include "TesterMenu.h"
#include "../../Users/Tester/Tester.h"

void TesterMenu::testerMenu() {
    cout << "1) Просмотреть свои предварительные результаты тестирования" << endl;
    cout << "2) Пройти новое тестирование" << endl;
    cout << "0) Вернуться назад" << endl;

    int action = getActionMenu(2);
    switch (action)
    {
        case 1:
            cout << "Просмотр" << endl;
            break; //TODO:
        case 2:
            {
                cout << "новое тестирование" << endl;
                TestManager pathToTest("../../../data/dataTest");
                FileWriteReadTest test;

                pathToTest.showFiles();
                cout << " Введите номер категории" << endl;
                action = getActionMenu(pathToTest.getDirSize(),1);
                system("cls");
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
                        pathToTest.setNewPath(pathToTest.getFileName(action));
                        test.setPathToTest(pathToTest.getPath());
                        test.readTest();
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
