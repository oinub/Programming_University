#include "Product.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

Product::Product() : expirationDate(0), price(0) {}

Product::Product(const std::string& name, const std::string& description,
    int expirationDate, size_t price, const std::string& place,
    const std::vector<Ingredient>& ingredients)
    : name(name), description(description),
    expirationDate(expirationDate), price(price), place(place),
    ingredients(ingredients) {
}

Product::Product(const Product& other) = default;
Product::~Product() = default;

Product& Product::operator=(const Product& other) {
    if (this != &other) {
        name = other.name;
        description = other.description;
        expirationDate = other.expirationDate;
        price = other.price;
        place = other.place;
        ingredients = other.ingredients;
    }
    return *this;
}

Product Product::operator+(const Product& other) const {
    Product result;
    result.name = this->name + " & " + other.name;
    result.description = this->description + " " + other.description;
    result.expirationDate = std::min(this->expirationDate, other.expirationDate);
    result.price = static_cast<size_t>((this->price + other.price) * 0.9);
    result.place = this->place + " / " + other.place;

    std::vector<Ingredient> newIngredients;
    for (const auto& ing : this->ingredients) {
        bool found = false;
        for (const auto& existing : newIngredients) {
            if (existing.name == ing.name) {
                found = true;
                break;
            }
        }
        if (!found) newIngredients.push_back(ing);
    }
    for (const auto& ing : other.ingredients) {
        bool found = false;
        for (const auto& existing : newIngredients) {
            if (existing.name == ing.name) {
                found = true;
                break;
            }
        }
        if (!found) newIngredients.push_back(ing);
    }
    result.ingredients = newIngredients;
    return result;
}

Product Product::operator-(const Product& other) const {
    Product result = *this;
    result.name = "выбор " + this->name + " без " + other.name;
    result.price = static_cast<size_t>(this->price * 0.9);
    result.expirationDate = std::max(0, this->expirationDate - 2);

    std::vector<Ingredient> newIngredients;
    for (const auto& ing : this->ingredients) {
        bool inOther = false;
        for (const auto& otherIng : other.ingredients) {
            if (ing.name == otherIng.name) {
                inOther = true;
                break;
            }
        }
        if (!inOther) {
            bool alreadyAdded = false;
            for (const auto& added : newIngredients) {
                if (added.name == ing.name) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) newIngredients.push_back(ing);
        }
    }
    newIngredients.push_back(Ingredient("консервант Т1000", 1.0));
    result.ingredients = newIngredients;
    return result;
}

Product& Product::operator-=(const Product& other) {
    if (this != &other) *this = *this - other;
    return *this;
}

// Геттеры
std::string Product::getName() const { return name; }
std::string Product::getDescription() const { return description; }
int Product::getExpirationDate() const { return expirationDate; }
size_t Product::getPrice() const { return price; }
std::string Product::getPlace() const { return place; }
std::vector<Ingredient> Product::getIngredients() const { return ingredients; }

bool Product::hasIngredient(const std::string& ingredientName) const {
    for (const auto& ing : ingredients) {
        if (ing.name == ingredientName) return true;
    }
    return false;
}

bool Product::isExpired(int currentDate) const {
    return currentDate > expirationDate;
}

void Product::setPrice(size_t newPrice) { price = newPrice; }
void Product::setExpirationDate(int days) { expirationDate = days; }

// ✅ КРАТКАЯ ИНФОРМАЦИЯ (ОДИН МЕТОД!)
void Product::print() const {
    std::cout << " " << name << " | Цена: " << price
        << " | Срок: " << expirationDate << " дн."
        << " | Место: " << place << std::endl;
}

// ✅ ПОЛНАЯ ИНФОРМАЦИЯ
void Product::printFull() const {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "           ПОЛНАЯ ИНФОРМАЦИЯ О ТОВАРЕ" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << " Название: " << name << std::endl;
    std::cout << " Описание: " << description << std::endl;
    std::cout << " Цена: " << price << " руб." << std::endl;
    std::cout << " Срок годности: " << expirationDate << " дней" << std::endl;
    std::cout << " Место: " << place << std::endl;
    std::cout << " Состав:" << std::endl;
    if (ingredients.empty()) {
        std::cout << "  (нет ингредиентов)" << std::endl;
    }
    else {
        for (const auto& ing : ingredients) {
            std::cout << "  • " << ing.name << ": " << std::fixed
                << std::setprecision(2) << ing.volume << " ед." << std::endl;
        }
    }
    std::cout << std::string(50, '=') << std::endl;
}

// ✅ ТОЛЬКО ИНГРЕДИЕНТЫ
void Product::printIngredients() const {
    std::cout << " Состав продукта '" << name << "':" << std::endl;
    Ingredient::printList(ingredients);
}

// ✅ СТАТУС СРОКА
void Product::printExpirationStatus(int currentDate) const {
    std::cout << " Продукт '" << name << "': ";
    if (isExpired(currentDate)) {
        std::cout << "⚠ ПРОСРОЧЕН! (срок: " << expirationDate
            << " дн., текущий день: " << currentDate << ")" << std::endl;
    }
    else {
        int daysLeft = expirationDate - currentDate;
        std::cout << " годен, осталось " << daysLeft << " дн." << std::endl;
    }
}

// ✅ СПИСОК ПРОДУКТОВ
void Product::printList(const std::vector<Product>& products,
    const std::string& title) {
    std::cout << "\n" << title << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    if (products.empty()) {
        std::cout << "  (список пуст)" << std::endl;
        return;
    }
    for (size_t i = 0; i < products.size(); ++i) {
        std::cout << std::setw(3) << (i + 1) << ". ";
        products[i].print();
    }
    std::cout << std::string(40, '-') << std::endl;
    std::cout << "Всего продуктов: " << products.size() << std::endl;
}

// ✅ СРАВНЕНИЕ
void Product::printComparison(const Product& p1, const Product& p2) {
    std::cout << "\n СРАВНЕНИЕ ПРОДУКТОВ:" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::left
        << std::setw(25) << "Критерий"
        << std::setw(25) << p1.getName()
        << p2.getName() << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << std::left
        << std::setw(25) << "Цена:"
        << std::setw(25) << (std::to_string(p1.getPrice()) + " руб.")
        << p2.getPrice() << " руб." << std::endl;
    std::cout << std::left
        << std::setw(25) << "Срок годности:"
        << std::setw(25) << (std::to_string(p1.getExpirationDate()) + " дн.")
        << p2.getExpirationDate() << " дн." << std::endl;
    std::cout << std::left
        << std::setw(25) << "Место:"
        << std::setw(25) << p1.getPlace()
        << p2.getPlace() << std::endl;
    std::cout << std::left
        << std::setw(25) << "Кол-во ингредиентов:"
        << std::setw(25) << p1.getIngredients().size()
        << p2.getIngredients().size() << std::endl;
}