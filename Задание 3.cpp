#include <iostream>
#include <stdexcept>

using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
 * @brief Вычисляет время, за которое путник одолел первую половину пути.
 * Функция принимает три времени и три скорости, затем вычисляет общее расстояние
 * и определяет время, за которое путник преодолел первую половину этого расстояния.
 * @param t1 Время движения с первой скоростью (часы).
 * @param v1 Первая скорость (км/ч).
 * @param t2 Время движения со второй скоростью (часы).
 * @param v2 Вторая скорость (км/ч).
 * @param t3 Время движения с третьей скоростью (часы).
 * @param v3 Третья скорость (км/ч).
 * @return Время, за которое путник одолел первую половину пути (часы).
 */
double calculateFirstHalfTime(const double t1, const double v1, const double t2, const double v2, const double t3, const double v3);

int main() 
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите данные о движении путника:" << endl;

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

    cout << "Время, за которое путник одолел первую половину пути: " << firstHalfTime << " часов." << endl;

    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

double calculateFirstHalfTime(double t1, double v1, double t2, double v2, double t3, double v3) {
    double distance1 = t1 * v1; // Расстояние на первой части пути
    double distance2 = t2 * v2; // Расстояние на второй части пути
    double distance3 = t3 * v3; // Расстояние на третьей части пути

    double totalDistance = distance1 + distance2 + distance3; // Общее расстояние
    double halfDistance = totalDistance / 2; // Половина пути

    double timeSpent = 0; // Время, затраченное на первую половину пути

    // Определяем, сколько времени требуется для достижения половины пути
    if (halfDistance <= distance1) {
        timeSpent = halfDistance / v1; // Если первая половина пути укладывается в первую часть
    }
    else {
        timeSpent += t1; // Учитываем все время первой части
        halfDistance -= distance1; // Вычитаем пройденное расстояние
        if (halfDistance <= distance2) {
            timeSpent += halfDistance / v2; // Вторая часть пути
        }
        else {
            timeSpent += t2; // Учитываем все время второй части
            halfDistance -= distance2; // Вычитаем пройденное расстояние
            timeSpent += halfDistance / v3; // Остаток пути на третьей части
        }
    }

    return timeSpent;
}