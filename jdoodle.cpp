#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x = 0.78;
    double y = 1.24;
    double z = 0.75;
    
    double chislitel = 2 * pow(z, x);
    double znamenatel = sqrt(pow(y, x) * pow(cos(x+y), 2) - 3 * z);
    double a = chislitel/znamenatel;
    
    double b = x * exp(sqrt(z)) * cos(pow(x, 2) / (y * z));
    
    cout << "Миненко Алексей Сергеевич ТСА-143, вариант 17" << endl;
    cout << "Дано:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    
    cout << "\nРезультат:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
}