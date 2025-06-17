#include <iostream>
#include <cmath>
#include <iomanip> // Для форматирования вывода

using namespace std;

/**@brief-функция вычисления a по заданному уравнению
*@param x-значение переменной x
*@param y-значение переменной y
*@param z-значение переменной z
*/
double getA(const double x, const double y, const double z);

/**@brief-функция вычисления b по заданному уравнению
*@param x-значение переменной x
*@param y-значение переменной y
*@param z-значение переменной z
*/
double getB(const double x, const double y, const double z);

/**@brief-точка входа в программу
*@return-возвращает 0
*/
int main()
{
    const double x = 0.78; // Пример значения
    const double y = 1.24; // Пример значения
    const double z = 0.5;  // Пример значения
    
    // Вывод результатов
    cout << "\nРезультаты вычислений:" << endl;
    cout << "a = " << fixed << setprecision(6) << getA(x, y, z) << endl;  // вывод
    cout << "b = " << fixed << setprecision(6) << getB(x, y, z) << endl;  // вывод

    return 0;
}

double getA(const double x, const double y, const double z)
{
    return (2 * pow(z, x)) / (sqrt(pow(y, x) * pow(cos(x + y), 2)) - 3 * z);
}

double getB(const double x, const double y, const double z)
{
    return exp(sqrt(z)) * cos(pow(x, 2) / (y * z));
}