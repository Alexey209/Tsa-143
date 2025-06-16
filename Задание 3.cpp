#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

/**
* @brief Считывает значение с клавиатуры с проверкой ввода
* @return возвращает корректное значение
* @throw завершает программу при некорректном вводе
*/
double getValue();

/**
 * @brief Вычисляет время, за которое путник одолел первую половину пути
 * @param t1 Время движения с первой скоростью (часы)
 * @param v1 Первая скорость (км/ч)
 * @param t2 Время движения со второй скоростью (часы)
 * @param v2 Вторая скорость (км/ч)
 * @param t3 Время движения с третьей скоростью (часы)
 * @param v3 Третья скорость (км/ч)
 * @return Время, за которое путник одолел первую половину пути (часы)
 */
double calculateFirstHalfTime(double t1, double v1, double t2, double v2, double t3, double v3);

int main() 
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите данные о движении путника:" << endl;

    try {
        cout << "Время движения с первой скоростью (t1): ";
        double t1 = getValue();

        cout << "Скорость 1 (v1): ";
        double v1 = getValue();

        cout << "Время движения со второй скоростью (t2): ";
        double t2 = getValue();

        cout << "Скорость 2 (v2): ";
        double v2 = getValue();

        cout << "Время движения с третьей скоростью (t3): ";
        double t3 = getValue();

        cout << "Скорость 3 (v3): ";
        double v3 = getValue();

        double firstHalfTime = calculateFirstHalfTime(t1, v1, t2, v2, t3, v3);

        cout << "Время, за которое путник одолел первую половину пути: " 
             << firstHalfTime << " часов." << endl;
    } 
    catch (...) {
        cerr << "Произошла ошибка при выполнении программы" << endl;
        return 1;
    }

    return 0;
}

double getValue()
{
    double value = 0.0;
    cin >> value;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Ошибка: введено некорректное значение!" << endl;
        abort();
    }

    if (value < 0) {
        cerr << "Ошибка: значение не может быть отрицательным!" << endl;
        abort();
    }

    return value;
}

double calculateFirstHalfTime(double t1, double v1, double t2, double v2, double t3, double v3) 
{
    double distance1 = t1 * v1;
    double distance2 = t2 * v2;
    double distance3 = t3 * v3;

    double totalDistance = distance1 + distance2 + distance3;
    double halfDistance = totalDistance / 2;

    double timeSpent = 0.0;

    if (halfDistance <= distance1) {
        timeSpent = halfDistance / v1;
    }
    else {
        timeSpent += t1;
        halfDistance -= distance1;
        
        if (halfDistance <= distance2) {
            timeSpent += halfDistance / v2;
        }
        else {
            timeSpent += t2;
            halfDistance -= distance2;
            timeSpent += halfDistance / v3;
        }
    }

    return timeSpent;
}
