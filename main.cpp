#include <iostream>
#include <cmath>
using namespace std;

/** 
 *@brief - функция для вычисления A по заданному уравнению
 * @param x - значение переменной x
 * @param y - значение перемнной y
 * @param z -значение переменной z
 * @return - возвращает рассчитанное значение 
 */
 double getA(const double x, const double y, const double z);
 
 /**
  *@brief - Функция для вычисления B по заданному уравнению 
  *@param x - значение переменной x
  *@param y - значение переменной y
  *@param z - значение переменной z
  *@return - возвращает рассчитанное значение 
  */
  double getB(const double x, const double y, const double z);
  /**
   *@brief - точка входа в программу
   *@return - возвращает 0, если программа выполненна корректно
   */
  int main()
{
const double x = 0.78;
const double y = 1.24;
const double z = 0.5;
cout<<"A = "<<getA(x,y,z)<<endl;
cout<<"B = "<<getB(x,y,z);
return 0;
}
double getA(const double x, const double y, const double z)
{
    return (2 * pow(z, x)) / (sqrt(pow(y, x) * pow(cos(x + y), 2)) - 3 * z);
}
double getB (const double x, const double y, const double z)
{
    return x * exp(sqrt(z)) * cos(pow(x, 2) / (y * z));
}