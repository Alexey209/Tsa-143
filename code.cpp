#include <iostream>
#include <limits> 
using namespace std;

/**
 * @brief Перевод веса из граммов в унции
 * @param gramms вес в граммах
 * @param ounces константа для перевода (1 унция = 28.3 грамма)
 * @return возвращает значение в унциях 
 */
double gramms_to_ounces(double gramms, double const ounces);

/**
 * @brief Запрашивает ввод данных с клавиатуры
 * @return возвращает значение в граммах
 */
double get_input();

int main() {
    setlocale(LC_ALL, "ru");
    const double ounces = 28.3;

    double gramms = get_input();
    if (gramms < 0) {
        cout << "Ошибка: вес не может быть отрицательным!" << endl;
        return 1;
    }

    cout << "Ввод выполнен корректно!" << endl;
    cout << "Вес в унциях: " << gramms_to_ounces(gramms, ounces) << endl;

    return 0;
}

double gramms_to_ounces(double gramms, double const ounces) {
    return gramms / ounces;
}

double get_input() {
    double gramms = 0;
    cout << "Введите вес в граммах: ";
    cin >> gramms;

    // Проверка на корректность ввода
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Будет использовано значение по умолчанию (0)." << endl;
        return 0;
    }

    return gramms;
}
