#include <vector>
#include <array>
#include <cstdlib>
#include <iostream>
#include <ctime>
void function_1(const std::vector<int>&vec) {

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;
}

void function_2(std::vector<int>& vec) {
    int num;
    std::cout << "Введите число для добавления в начало: ";
    std::cin >> num;
    vec.insert(vec.begin(), num);

    std::cout << "Обновленный массив: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void function_3(std::vector<int>& vec) {
    int n;
    std::cout << "Введите число для добавления в конец: ";
    std::cin >> n;
    vec.push_back(n);

    std::cout << "Обновленный массив: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void function_4(std::vector<int>& vec) {
    vec.clear();
    std::cout << "Массив очищен." << std::endl;
}

void function_5(const std::vector<int>& vec) {
    int index;
    std::cout << "Введите индекс для поиска: ";
    std::cin >> index;

    if (index >= 0 && index < vec.size()) {
        int element = vec[index];
        std::cout << "Индекс: " << index << " Элемент: " << element << std::endl;
    }
    else {
        std::cout << "Неверный индекс!" << std::endl;
    }
}

void function_6(std::vector<int>& vec) {
    std::cout << "Исходный массив: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> result;
    bool foundNumbers = false;

    for (int i = vec.size() - 1; i >= 0; i--) {
        int num = vec[i];

        if (num % 7 == 0 && num != 777) {
            foundNumbers = true;
            continue;
        }

        result.push_back(num);
    }

    if (foundNumbers == false) {
        result.push_back(0);
        result.push_back(0);
        result.push_back(0);
        std::cout << "Не найдено чисел кратных 7 (кроме 777). Добавлены три нуля в конец." << std::endl;
    }

    vec = result;

    std::cout << "Результат: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


std::vector<int> vec1() {
    std::vector<int> vec;
    vec.reserve(1000);
    return vec;
}

const int SIZE = 10;

void bubbleSortAscending(std::array<int, SIZE>& arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(std::array<int, SIZE>& arr) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 1. ПЕРЕДАЧА ПО ЗНАЧЕНИЮ (копия массива)
void sortByValue(std::array<int, SIZE> arr, bool ascending) {
    std::cout << "1. ПЕРЕДАЧА ПО ЗНАЧЕНИЮ:" << std::endl;
    std::cout << "Передача std::array в функцию по значению создает КОПИЮ массива." << std::endl;
    std::cout << "Изменения внутри функции НЕ влияют на оригинальный массив." << std::endl;

    std::cout << "По значению - ДО сортировки (в функции): ";
    for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    if (ascending) {
        bubbleSortAscending(arr);
    }
    else {
        bubbleSortDescending(arr);
    }

    std::cout << "По значению - ПОСЛЕ сортировки (в функции): ";
    for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// 2. ПЕРЕДАЧА ПО ССЫЛКЕ (работа с оригиналом)
void sortByReference(std::array<int, SIZE>& arr, bool ascending) {
    std::cout << "2. ПЕРЕДАЧА ПО ССЫЛКЕ:" << std::endl;
    std::cout << "Передача std::array в функцию по ссылке работает с ОРИГИНАЛОМ." << std::endl;
    std::cout << "Изменения внутри функции напрямую влияют на оригинальный массив." << std::endl;

    std::cout << "По ссылке - ДО сортировки (в функции): ";
    for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    if (ascending) {
        bubbleSortAscending(arr);
    }
    else {
        bubbleSortDescending(arr);
    }

    std::cout << "По ссылке - ПОСЛЕ сортировки (в функции): ";
    for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// 3. ПЕРЕДАЧА ПО КОНСТАНТНОЙ ССЫЛКЕ (только для чтения)
void sortByConstReference(const std::array<int, SIZE>& arr, bool ascending) {
    std::cout << "3. ПЕРЕДАЧА ПО КОНСТАНТНОЙ ССЫЛКЕ:" << std::endl;
    std::cout << "Передача std::array по константной ссылке - только для чтения." << std::endl;
    std::cout << "Невозможно изменить массив, но эффективно для больших данных." << std::endl;

    std::cout << "По константной ссылке - массив (только чтение): ";
    for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void fillRandomArray(std::array<int, SIZE>& arr) {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 21 - 10;
        arr[i] = rand() % 21 - 10;
    }
}

void printArray(const std::array<int, SIZE>& arr, const std::string& message) {
    std::cout << message << ": ";
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void copyArray(int source[SIZE], int destination[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        destination[i] = source[i];
    }
}

void function_7() {
    std::array<int, SIZE> originalArr;
    fillRandomArray(originalArr);
    printArray(originalArr, "Исходный массив");

    // 1. ПЕРЕДАЧА ПО ЗНАЧЕНИЮ
    std::array<int, SIZE> arr1 = originalArr;
    std::cout << "В main до вызова: ";
    printArray(arr1, "");

    sortByValue(arr1, true);

    std::cout << "В main после вызова: ";
    printArray(arr1, "");
    std::cout << "Оригинальный массив НЕ изменился!" << std::endl;
    std::cout << "Преимущество: std::array автоматически копируется!" << std::endl << std::endl;

    // 2. ПЕРЕДАЧА ПО ССЫЛКЕ
    std::array<int, SIZE> arr2 = originalArr;
    std::cout << "В main до вызова: ";
    printArray(arr2, "");

    sortByReference(arr2, false);

    std::cout << "В main после вызова: ";
    printArray(arr2, "");
    std::cout << "Оригинальный массив ИЗМЕНИЛСЯ!" << std::endl;
    std::cout << "Преимущество: работа с оригиналом, нет копирования!" << std::endl << std::endl;

    // 3. ПЕРЕДАЧА ПО КОНСТАНТНОЙ ССЫЛКЕ
    std::cout << "В main перед вызовом с константной ссылкой: ";
    printArray(originalArr, "");

    sortByConstReference(originalArr, true);

    std::cout << "В main после вызова: ";
    printArray(originalArr, "");
    std::cout << "Оригинальный массив НЕ изменился (константная ссылка)!" << std::endl;
    std::cout << "Преимущество: безопасность + эффективность!" << std::endl << std::endl;
}

void menu(std::vector<int>& vec) {
    int choice;

    std::cout << "=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
    std::cout << "1. Просмотр массива" << std::endl;
    std::cout << "2. Добавить элемент в начало" << std::endl;
    std::cout << "3. Добавить элемент в конец" << std::endl;
    std::cout << "4. Очистка всего массива" << std::endl;
    std::cout << "5. Поиск элемента в массиве" << std::endl;
    std::cout << "6. Задание 7 варианта" << std::endl;
    std::cout << "7. Пункт 2" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "Выберите пункт: ";

    std::cin >> choice;

    switch (choice) {
    case 1:
        function_1(vec);
        break;
    case 2:
        function_2(vec);
        break;
    case 3:
        function_3(vec);
        break;
    case 4:
        function_4(vec);
        break;
    case 5:
        function_5(vec);
        break;
    case 6:
        function_6(vec);
        break;
    case 7:
        function_7();
        break;
    case 0:
        std::cout << "Выход из программы..." << std::endl;
        exit(0);
        break;
    default:
        std::cout << "Неверный пункт меню! Попробуйте снова." << std::endl;
        break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> vec = vec1();
    vec.reserve(1000);
    while (true) {
        menu(vec);
    }
    return 0;
}
/*
Пункт 3:
std::vector и std::array выполняют одинаковую роль только когда:
1. Размер фиксирован и известен при компиляции
2. Не требуется изменение размера
3. Доступ только по индексу

В этой лабе не было выбора потому что в первом пункте мы не знаем длину массива и можем её сами изменять, для этого не подходит std::array,
так как это статический массив и его длину нельзя поменять. А так как мы изменяли длину массива, добавляя числа в конец и начало надо использовать std::vector.
Во втором пункте можно использовать std::vector, но из за условия того, что мы не можем использовать, то же самое, что в первом пункте, то используем std::array.
*/
