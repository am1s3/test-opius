#include <iostream>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));
    short range;
    bool corNumTrue = true;
    bool getRange = false;
    short corNum;
    short enterGame;
    bool enterGameTrue;
    short attempt = 0;

    cout << "v1.5.0" << '\n';

    do {
        cout << "Игра угадай число! Хотите продолжить? 1 - да/ 2 нет: ";

        if (!(cin >> enterGame)) {
            cout << "Ошибка!" << '\n';
            enterGameTrue = false;
        } else if (enterGame != 1 && enterGame != 2) {
            cout << "Ошибка!" << '\n';
            enterGameTrue = false;
        } else if (enterGame == 2) {
            cout << "Выход из игры" << '\n';
            return 0;
        } else {
            enterGameTrue = true;
        }
    } while (enterGameTrue == false);

    do {
        cout << "Выберете радиус для отгадки: ";

        if (!(cin >> range)) {
            cout << "Ошибка!" << '\n';
            getRange = false;
        } else if (range <= 0) {
            cout << "Число не может быть меньше 0" << '\n';
            getRange = false;
        } else {
            cout << "Выбраный радиус от 1 до " << range << '\n';
            getRange = true;
        }
    } while (getRange == false);

    if (enterGame == 1) {
        cout << "Отгадывай число в радиусе от 1 до " << range << "." << '\n';
    short ranNum = 1 + rand() % range;
        do {

            cout << "Число: ";
            
            cin >> corNum;
            attempt++;

            if (corNum > range) {
                cout << "Число привышает радиус для отгадки! Радиус от 1 до " << range << '\n';
                corNumTrue = false;
            } else if (corNum <= 0) {
                cout << "Число не может быть меньше 0" << '\n';
                corNumTrue = false;
            } else if (corNum < ranNum) {
                cout << "Неправильно! Число больше!" << '\n';
                corNumTrue = false;
            } else if (corNum > ranNum) {
                cout << "Неправильно! Число меньше!" << '\n';
                corNumTrue = false;
            } else if (corNum == ranNum) {
                cout << "Правильно! Ты отгадал, загаданое число было " << ranNum << "!" << '\n';
                cout << "Ты потратил " << attempt << " попыток" << '\n';
                corNumTrue = true;
            }
        } while (corNumTrue == false);
    }
    return 0;
}