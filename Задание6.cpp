/**
 * @file array_operations.cpp
 * @brief Программа для работы с динамическим массивом целых чисел
 * 
 * Программа предоставляет следующие функции:
 * 1. Заполнение массива вручную или случайными числами
 * 2. Вычисление произведения четных элементов
 * 3. Замена элементов с нечетными индексами на квадраты их номеров
 * 4. Проверка наличия положительных элементов, которые при делении на k дают остаток 2
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

/**
 * @brief Безопасно получает целое число от пользователя
 * @return Введенное пользователем целое число
 * @note При ошибке ввода завершает программу
 */
int getValue();

/**
 * @brief Получает размер массива от пользователя
 * @return Размер массива как size_t
 * @note Проверяет корректность введенного размера
 */
size_t getSize();

/**
 * @brief Проверяет корректность размера массива
 * @param n Проверяемый размер
 * @note Завершает программу при n <= 0
 */
void checkN(const int n);

/**
 * @brief Заполняет массив значениями, вводимыми пользователем
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void fillArray(int* arr, const int n);

/**
 * @brief Заполняет массив случайными числами в диапазоне [-15, 15]
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void fillArrayRandom(int* arr, const int n);

/**
 * @brief Выводит элементы массива на экран
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void printArray(int* arr, const int n);

/**
 * @brief Вычисляет произведение четных элементов массива
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Произведение четных элементов или 0, если таких нет
 */
int productOfEvenElements(int* arr, const int n);

/**
 * @brief Заменяет элементы с нечетными индексами на квадраты их номеров
 * @param arr Указатель на массив
 * @param n Размер массива
 * @note Номера элементов = индексы + 1
 */
void replaceOddIndexesWithSquares(int* arr, const int n);

/**
 * @brief Проверяет наличие положительных элементов, дающих остаток 2 при делении на k
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param k Делитель
 * @return true если такие элементы есть, false если нет или k=0
 */
bool hasPositiveElementsDivisibleByKWithRemainder2(int* arr, const int n, int k);

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    size_t n = getSize();
    int* arr = new int[n];

    cout << "Заполнить массив вручную (1) или случайными числами (2)? ";
    int choice = getValue();
    if (choice == 1) {
        fillArray(arr, n);
    } else if (choice == 2) {
        fillArrayRandom(arr, n);
    } else {
        cout << "Неверный выбор. Программа завершена." << endl;
        delete[] arr;
        return 1;
    }

    printArray(arr, n);

    // 1. Найти произведение элементов с четными значениями
    int product = productOfEvenElements(arr, n);
    cout << "Произведение четных элементов: " << product << endl;

    // 2. Заменить элементы с нечетными индексами на квадраты их индексов
    replaceOddIndexesWithSquares(arr, n);
    cout << "Массив после замены: ";
    printArray(arr, n);

    // 3. Проверить наличие положительных элементов, делящихся на k с остатком 2
    cout << "Введите число k: ";
    int k = getValue();
    bool hasElements = hasPositiveElementsDivisibleByKWithRemainder2(arr, n, k);
    if (hasElements) {
        cout << "В массиве есть такие элементы." << endl;
    } else {
        cout << "В массиве нет таких элементов." << endl;
    }

    delete[] arr;
    return 0;
}

int getValue() {
    int value = 0;
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Программа будет завершена." << endl;
        abort();
    }
    return value;
}

size_t getSize() {
    cout << "Введите размер массива n: ";
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n) {
    if (n <= 0) {
        cout << "Размер массива должен быть положительным. Программа будет завершена." << endl;
        abort();
    }
}

void fillArray(int* arr, const int n) {
    for (size_t i = 0; i < n; i++) {
        cout << "Введите arr[" << i + 1 << "] = ";
        arr[i] = getValue();
    }
}

void fillArrayRandom(int* arr, const int n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % 31 - 15; // Диапазон [-15, 15]
    }
}

void printArray(int* arr, const int n) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int productOfEvenElements(int* arr, const int n) {
    int product = 1;
    bool hasEven = false;

    for (size_t i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            product *= arr[i];
            hasEven = true;
        }
    }

    return hasEven ? product : 0;
}

void replaceOddIndexesWithSquares(int* arr, const int n) {
    for (size_t i = 0; i < n; i++) {
        if (i % 2 != 0) { // Нечетные индексы 
            arr[i] = (i + 1) * (i + 1); // Квадрат номера (не индекса)
        }
    }
}

bool hasPositiveElementsDivisibleByKWithRemainder2(int* arr, const int n, int k) {
    if (k == 0) return false; // Деление на ноль невозможно

    for (size_t i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] % k == 2) {
            return true;
        }
    }
    return false;
}
