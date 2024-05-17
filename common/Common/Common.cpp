#include "Common.h"

// Функция принимает
// макс. вариант, мин. вариант - дефолт 0
// делает проверку и возвращает выбранный варинт если такой есть
int Common::getAction(int maxVarAction, int minVarAction) {
    int action;
    cin >> action;

    // если ввели не число
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        throw invalid_argument("Error type");
    }

    if (action < minVarAction || action > maxVarAction)
        throw out_of_range("Error range");

    return action;
}
