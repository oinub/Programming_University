#include "Product.hpp"
#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "Russian");

    Product Milk;
    Product Bread("Bread", "Tasty Bread", 5, 47, "Svetlogorsk", { "Пшеница, мука, яйцо" });
    Product Eggs = Bread;

    std::cout << " ТЕСТ 1: Оператор + " << std::endl;
    Product Combined = Bread + Eggs;
    Combined.GetAll();

    std::cout << "\n ТЕСТ 2: Оператор - " << std::endl;
    Product Subtracted = Bread - Eggs;
    Subtracted.GetAll();

    std::cout << "\n ТЕСТ 3: Оператор -= " << std::endl;
    Product Test = Bread;
    std::cout << "До операции -= :" << std::endl;
    Test.GetAll();

    Test -= Eggs;

    std::cout << "После операции -= :" << std::endl;
    Test.GetAll();

    std::cout << "\n ТЕСТ 4: Проверка исходных объектов " << std::endl;
    Bread.GetAll();
    Eggs.GetAll();

    return 0;
}