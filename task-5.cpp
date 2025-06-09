#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

/**
* @brief Вычисляет сумму первых n членов последовательности
* @param n Количество членов последовательности
* @return Сумма первых n членов
*/
double sumFirstN(const int n);

/**
* @brief Вычисляет сумму членов последовательности, не меньших по модулю e
* @param e Заданное число (порог)
* @return Сумма подходящих членов
*/
double sumModuloE(const double e);

/**
* @brief Вычисляет факториал числа
* @param n Число
* @return n!
*/
unsigned long long factorial(int n);

/**
* @brief Вычисляет общий член последовательности
* @param k Индекс члена
* @return (-1)^k / (k! * (k+1)!)
*/
double sequenceTerm(const int k);

/**
* @brief Проверяет корректность ввода n
* @return n, если ввод корректен, иначе -1
*/
int getValidN();

/**
* @brief Проверяет корректность ввода e
* @return e, если ввод корректен, иначе -1
*/
double getValidE();

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int n = getValidN();
    if (n == -1)
    {
        return 1;
    }
    cout << "Сумма первых " << n << " членов последовательности: " << sumFirstN(n) << endl;

    double e = getValidE();
    if (e == -1)
    {
        return 1;
    }
    cout << "Сумма членов последовательности, |aₖ| ≥ " << e << ": " << sumModuloE(e) << endl;

    return 0;
}

int getValidN()
{
    int n;
    cout << "Введите n: ";
    cin >> n;
    
    if (cin.fail() || n <= 0)
    {
        cout << "Ошибка: n должно быть положительным целым числом." << endl;
        return -1;
    }
    
    return n;
}

double getValidE()
{
    double e;
    cout << "Введите e: ";
    cin >> e;
    
    if (cin.fail() || e <= 0)
    {
        cout << "Ошибка: e должно быть положительным числом." << endl;
        return -1;
    }
    
    return e;
}

double sumFirstN(const int n)
{
    double sum = 0;
    for (int k = 0; k <= n; ++k)
    {
        sum += sequenceTerm(k);
    }
    return sum;
}

double sumModuloE(const double e)
{
    double sum = 0;
    int k = 0;
    double term = sequenceTerm(k);
    
    while (abs(term) >= e)
    {
        sum += term;
        term = sequenceTerm(++k);
    }
    
    return sum;
}

unsigned long long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

double sequenceTerm(const int k)
{
    return (k % 2 == 0 ? 1 : -1) / (factorial(k) * factorial(k + 1.0));
}