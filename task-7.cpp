/**
 * @file array_operations.cpp
 * @brief Программа для работы с двумерными массивами (матрицами)
 * @details Программа позволяет создавать, заполнять и выполнять операции над матрицами:
 * - Замена минимальных по модулю элементов в столбцах нулями
 * - Удаление столбцов по условию (первый элемент больше последнего)
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

// Прототипы функций

/**
 * @brief Получает целое значение из ввода
 * @return Введенное целое число
 * @throw Завершает программу при ошибке ввода
 */
int getValue();

/**
 * @brief Получает размер для массива
 * @return Размер как size_t
 * @throw Завершает программу при неположительном размере
 */
size_t getSize();

/**
 * @brief Проверяет что число положительное
 * @param n Проверяемое число
 * @throw Завершает программу если n <= 0
 */
void checkN(const int n);

/**
 * @brief Создает новый двумерный массив
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Указатель на созданный массив
 */
int** getNewArray(const size_t rows, const size_t cols);

/**
 * @brief Выводит массив в консоль
 * @param array Массив для вывода
 * @param rows Количество строк
 * @param cols Количество столбцов
 */
void printArray(int** array, const size_t rows, const size_t cols);

/**
 * @brief Заполняет массив значениями вручную
 * @param array Массив для заполнения
 * @param rows Количество строк
 * @param cols Количество столбцов
 */
void fillArray(int** array, const size_t rows, const size_t cols);

/**
 * @brief Заполняет массив случайными числами
 * @param array Массив для заполнения
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param start Начало диапазона
 * @param end Конец диапазона
 */
void fillRandom(int** array, const size_t rows, const size_t cols, const int start, const int end);

/**
 * @brief Освобождает память массива
 * @param array Массив для удаления
 * @param rows Количество строк
 */
void deleteArray(int** array, const size_t rows);

/**
 * @brief Создает копию массива
 * @param array Исходный массив
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Указатель на копию массива
 */
int** copyArray(int** array, const size_t rows, const size_t cols);

// Функции для выполнения заданий

/**
 * @brief Заменяет минимальный по модулю элемент в столбцах нулями
 * @param array Массив для обработки
 * @param rows Количество строк
 * @param cols Количество столбцов
 */
void replaceMinAbsWithZero(int** array, const size_t rows, const size_t cols);

/**
 * @brief Удаляет столбцы где первый элемент больше последнего
 * @param array Исходный массив
 * @param rows Количество строк
 * @param cols Ссылка на количество столбцов (обновляется)
 * @return Новый массив с удаленными столбцами
 */
int** removeColumns(int** array, const size_t rows, size_t& cols);

enum {RANDOM = 1, MANUAL = 2}; ///< Варианты заполнения массива

int main() {
    cout << "Enter number of rows: ";
    size_t rows = getSize();
    cout << "Enter number of columns: ";
    size_t cols = getSize();
    
    int** array = getNewArray(rows, cols);
    
    cout << "Enter the way to fill array: " << MANUAL << " to fill manually, " 
         << RANDOM << " to fill randomly: ";
    int choice = getValue();
    
    int start = 0, end = 0;
    switch (choice) {
        case RANDOM:
            cout << "Enter start value: ";
            start = getValue();
            cout << "Enter end value: ";
            end = getValue();
            fillRandom(array, rows, cols, start, end);
            break;
        case MANUAL:
            fillArray(array, rows, cols);
            break;
        default:
            cout << "Error: invalid choice" << endl;
            deleteArray(array, rows);
            return 1;
    }
    
    cout << "\nOriginal array:" << endl;
    printArray(array, rows, cols);
    
    // Задание 1: Заменить минимальный по модулю элемент каждого столбца нулем
    int** arrayCopy1 = copyArray(array, rows, cols);
    replaceMinAbsWithZero(arrayCopy1, rows, cols);
    cout << "\nArray after replacing min abs elements with zeros:" << endl;
    printArray(arrayCopy1, rows, cols);
    deleteArray(arrayCopy1, rows);
    
    // Задание 2: Удалить столбцы, где первый элемент больше последнего
    int** arrayCopy2 = copyArray(array, rows, cols);
    size_t newCols = cols;
    int** resultArray = removeColumns(arrayCopy2, rows, newCols);
    cout << "\nArray after removing columns where first > last element:" << endl;
    printArray(resultArray, rows, newCols);
    
    // Освобождение памяти
    deleteArray(resultArray, rows);
    deleteArray(arrayCopy2, rows);
    deleteArray(array, rows);
    
    return 0;
}

// Реализация функций

int getValue() {
    int value = 0;
    cin >> value;
    if (cin.fail()) {
        cout << "Error" << endl;
        abort();
    }
    return value;
}

size_t getSize() {
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n) {
    if (n <= 0) {
        cout << "Error: size must be positive" << endl;
        abort();
    }
}

int** getNewArray(const size_t rows, const size_t cols) {
    int** array = new int*[rows];
    for (size_t i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    return array;
}

void printArray(int** array, const size_t rows, const size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << setw(6) << array[i][j];
        }
        cout << endl;
    }
}

void fillArray(int** array, const size_t rows, const size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << "Enter array[" << i << "][" << j << "] = ";
            array[i][j] = getValue();
        }
    }
}

void fillRandom(int** array, const size_t rows, const size_t cols, const int start, const int end) {
    srand(time(0));
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            array[i][j] = rand() % (end - start + 1) + start;
        }
    }
}

void deleteArray(int** array, const size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

int** copyArray(int** array, const size_t rows, const size_t cols) {
    int** newArray = getNewArray(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            newArray[i][j] = array[i][j];
        }
    }
    return newArray;
}

// Функции для выполнения заданий

void replaceMinAbsWithZero(int** array, const size_t rows, const size_t cols) {
    for (size_t j = 0; j < cols; j++) {
        size_t minAbsIndex = 0;
        for (size_t i = 1; i < rows; i++) {
            if (abs(array[i][j]) < abs(array[minAbsIndex][j])) {
                minAbsIndex = i;
            }
        }
        array[minAbsIndex][j] = 0;
    }
}

int** removeColumns(int** array, const size_t rows, size_t& cols) {
    // Сначала посчитаем, сколько столбцов нужно удалить
    size_t countToRemove = 0;
    for (size_t j = 0; j < cols; j++) {
        if (array[0][j] > array[rows-1][j]) {
            countToRemove++;
        }
    }
    
    size_t newCols = cols - countToRemove;
    int** newArray = getNewArray(rows, newCols);
    
    size_t newJ = 0;
    for (size_t j = 0; j < cols; j++) {
        if (array[0][j] <= array[rows-1][j]) {
            for (size_t i = 0; i < rows; i++) {
                newArray[i][newJ] = array[i][j];
            }
            newJ++;
        }
    }
    
    cols = newCols; // Обновляем количество столбцов
    return newArray;
}