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
* @brief Вычисляет общий член последовательности с использованием рекуррентных соотношений
* @param k Индекс члена
* @param prev_k_fact Значение k! на предыдущем шаге (по ссылке)
* @param prev_k1_fact Значение (k+1)! на предыдущем шаге (по ссылке)
* @return (-1)^k / (k! * (k+1)!)
*/
double sequenceTerm(const int k, double& prev_k_fact, double& prev_k1_fact);

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
    int n=0;
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
    double e=0;
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
    double k_fact = 1.0;     // 0! = 1
    double k1_fact = 1.0;    // 1! = 1
    
    for (int k = 0; k <= n; ++k)
    {
        double term = sequenceTerm(k, k_fact, k1_fact);
        sum += term;
    }
    return sum;
}

double sumModuloE(const double e)
{
    double sum = 0;
    int k = 0;
    double k_fact = 1.0;     // 0! = 1
    double k1_fact = 1.0;    // 1! = 1
    
    while (true)
    {
        double term = sequenceTerm(k, k_fact, k1_fact);
        if (abs(term) < e)
            break;
            
        sum += term;
        k++;
    }
    
    return sum;
}

double sequenceTerm(const int k, double& prev_k_fact, double& prev_k1_fact)
{
    if (k == 0)
    {
        prev_k_fact = 1.0;   // 0! = 1
        prev_k1_fact = 1.0;  // 1! = 1
    }
    else
    {
        // Используем рекуррентные соотношения:
        // k! = (k-1)! * k
        // (k+1)! = k! * (k+1)
        double current_k_fact = prev_k_fact * k;
        double current_k1_fact = current_k_fact * (k + 1);
        
        prev_k_fact = current_k_fact;
        prev_k1_fact = current_k1_fact;
    }
    
    return (k % 2 == 0 ? 1.0 : -1.0) / (prev_k_fact * prev_k1_fact);
}