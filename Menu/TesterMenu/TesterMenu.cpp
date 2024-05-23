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
            cout << "новое тестирование" << endl;
            break; //TODO:
        case 0:
            return;
    }

    testerMenu();
}
