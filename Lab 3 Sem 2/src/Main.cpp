#include <iostream>
#include <vector>
#include "Product.hpp"
#include "Commission.hpp"

void demonstrateAllPrintMethods() {
    std::cout << "\n" << std::string(70, '.') << std::endl;
    std::cout << "     ДЕМОНСТРАЦИЯ ВСЕХ МЕТОДОВ ПЕЧАТИ" << std::endl;
    std::cout << std::string(70, '.') << std::endl;

    std::cout << "\n ШАГ 1: Создание тестовых данных\n" << std::endl;

    Ingredient flour("Мука", 500.0);
    Ingredient sugar("Сахар", 200.0);
    Ingredient eggs("Яйца", 3.0);
    Ingredient milk("Молоко", 250.0);
    Ingredient poison("Мышьяк", 0.1);

    std::cout << " Созданы ингредиенты:" << std::endl;
    flour.print();
    sugar.print();
    eggs.print();
    milk.print();
    poison.print();

    std::cout << "\n ШАГ 2: Демонстрация методов Ingredient\n" << std::endl;

    std::vector<Ingredient> ingredients = { flour, sugar, eggs, milk };
    Ingredient::printList(ingredients, "Список ингредиентов для продукта:");

    std::cout << "\n ШАГ 3: Создание продуктов\n" << std::endl;

    Product bread("Хлеб", "Свежий ржаной хлеб", 5, 50, "Пекарня №1",
        { flour, sugar, eggs });

    Product cake("Торт", "Шоколадный торт", 3, 200, "Кондитерская",
        { flour, sugar, eggs, milk });

    Product dangerous("Опасный", "Содержит яд", 10, 500, "Подвал",
        { flour, poison });

    std::cout << "\n ШАГ 4: Демонстрация методов Product\n" << std::endl;

    std::cout << "--- Краткая информация (print()):" << std::endl;
    bread.print();
    cake.print();
    dangerous.print();

    std::cout << "\n--- Полная информация о хлебе (printFull()):" << std::endl;
    bread.printFull();

    std::cout << "\n--- Ингредиенты торта (printIngredients()):" << std::endl;
    cake.printIngredients();

    std::cout << "\n--- Статус срока годности (printExpirationStatus()):" << std::endl;
    bread.printExpirationStatus(3);
    bread.printExpirationStatus(6); 

    std::cout << "\n--- Список всех продуктов (printList()):" << std::endl;
    std::vector<Product> products = { bread, cake, dangerous };
    Product::printList(products, "Каталог продуктов:");

    std::cout << "\n--- Сравнение продуктов (printComparison()):" << std::endl;
    Product::printComparison(bread, cake);

    std::cout << "\n  ШАГ 5: Создание комиссий\n" << std::endl;

    Commission comm1("ул. Ленина, 10", { "Мышьяк", "Кокаин" }, 7);
    Commission comm2("пр. Мира, 15", { "Мышьяк", "Ртуть" }, 5);
    Commission comm3("ул. Советская, 20", {}, 10);

    std::cout << "\n ШАГ 6: Демонстрация методов Commission\n" << std::endl;

    std::cout << "--- Краткая информация (print()):" << std::endl;
    comm1.print();
    comm2.print();
    comm3.print();

    std::cout << "\n--- Полная информация о комиссии (printFull()):" << std::endl;
    comm1.printFull();

    std::cout << "\n--- Запрещенные ингредиенты (printBannedIngredients()):" << std::endl;
    comm1.printBannedIngredients();
    comm3.printBannedIngredients();

    std::cout << "\n--- Список всех комиссий (printList()):" << std::endl;
    std::vector<Commission> commissions = { comm1, comm2, comm3 };
    Commission::printList(commissions, "Реестр комиссий:");


    std::cout << "\n ШАГ 7: Проверка продуктов комиссией\n" << std::endl;

    std::cout << "Комиссия проверяет продукты:" << std::endl;
    comm1.print();

    std::cout << "\nРезультаты проверки:" << std::endl;
    std::cout << "------------------------" << std::endl;

    for (const auto& product : products) {
        std::cout << "Продукт: ";
        product.print();

        bool isLegal = comm1.checkProduct(product);
        std::cout << "Результат: " << (isLegal ? " ЛЕГАЛЕН" : " НЕЛЕГАЛЕН") << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    std::cout << "\n" << std::string(70, '.') << std::endl;
    std::cout << "           ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА" << std::endl;
    std::cout << std::string(70, '.') << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    demonstrateAllPrintMethods();
    return 0;
}