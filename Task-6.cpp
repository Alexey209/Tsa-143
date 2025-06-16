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
void fillArray(int* arr, const size_t n);

/**
 * @brief Заполняет массив случайными числами в диапазоне [-15, 15]
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void fillArrayRandom(int* arr, const size_t n);

/**
 * @brief Выводит элементы массива на экран
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void printArray(const int* arr, const size_t n);

/**
 * @brief Вычисляет произведение четных элементов массива
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Произведение четных элементов или 0, если таких нет
 */
int productOfEvenElements(const int* arr, const size_t n);

/**
 * @brief Создает копию массива с заменой элементов с нечетными индексами на квадраты их номеров
 * @param arr Указатель на исходный массив
 * @param n Размер массива
 * @return Указатель на новый массив с измененными значениями
 * @note Номера элементов = индексы + 1
 * @note Вызывающая сторона должна освободить память
 */
int* getArrayWithReplacedOddIndexes(const int* arr, const size_t n);

/**
 * @brief Проверяет наличие положительных элементов, дающих остаток 2 при делении на k
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param k Делитель
 * @return true если такие элементы есть, false если нет или k=0
 */
bool hasPositiveElementsDivisibleByKWithRemainder2(const int* arr, const size_t n, const int k);

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    size_t n = getSize();
    int* originalArr = new int[n];

    cout << "Заполнить массив вручную (1) или случайными числами (2)? ";
    int choice = getValue();
    switch (choice) {
        case 1:
            fillArray(originalArr, n);
            break;
        case 2:
            fillArrayRandom(originalArr, n);
            break;
        default:
            cout << "Неверный выбор. Программа завершена." << endl;
            delete[] originalArr;
            return 1;
    }

    cout << "Исходный массив: ";
    printArray(originalArr, n);

    // 1. Найти произведение элементов с четными значениями
    int product = productOfEvenElements(originalArr, n);
    cout << "Произведение четных элементов: " << product << endl;

    // 2. Создать копию с заменой элементов с нечетными индексами
    int* modifiedArr = getArrayWithReplacedOddIndexes(originalArr, n);
    cout << "Модифицированный массив: ";
    printArray(modifiedArr, n);
    delete[] modifiedArr; // Освобождаем память

    // 3. Проверить наличие положительных элементов, делящихся на k с остатком 2
    cout << "Введите число k: ";
    int k = getValue();
    bool hasElements = hasPositiveElementsDivisibleByKWithRemainder2(originalArr, n, k);
    if (hasElements) {
        cout << "В массиве есть такие элементы." << endl;
    } else {
        cout << "В массиве нет таких элементов." << endl;
    }

    delete[] originalArr;
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

void fillArray(int* arr, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << "Введите arr[" << i + 1 << "] = ";
        arr[i] = getValue();
    }
}

void fillArrayRandom(int* arr, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % 31 - 15; // Диапазон [-15, 15]
    }
}

void printArray(const int* arr, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int productOfEvenElements(const int* arr, const size_t n) {
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

int* getArrayWithReplacedOddIndexes(const int* arr, const size_t n) {
    int* modifiedArr = new int[n]; // Создаем новый массив

    for (size_t i = 0; i < n; i++) {
        if (i % 2 != 0) { // Нечетные индексы
            modifiedArr[i] = (i + 1) * (i + 1); // Квадрат номера (не индекса)
        } else {
            modifiedArr[i] = arr[i]; // Копируем остальные элементы
        }
    }

    return modifiedArr;
}

bool hasPositiveElementsDivisibleByKWithRemainder2(const int* arr, const size_t n, const int k) {
    if (k == 0) return false; // Деление на ноль невозможно

    for (size_t i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] % k == 2) {
            return true;
        }
    }
    
    return false;
}