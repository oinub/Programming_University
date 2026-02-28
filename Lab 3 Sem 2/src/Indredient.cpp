#include "Ingredient.hpp"
#include <iomanip>
#include <iostream>

Ingredient::Ingredient() : name(""), volume(0.0) {}

Ingredient::Ingredient(const std::string& name, double volume)
    : name(name), volume(volume) {
}

Ingredient::Ingredient(const Ingredient& other)
    : name(other.name), volume(other.volume) {
}

Ingredient& Ingredient::operator=(const Ingredient& other) {
    if (this != &other) {
        name = other.name;
        volume = other.volume;
    }
    return *this;
}

bool Ingredient::operator==(const Ingredient& other) const {
    return name == other.name;
}

Ingredient::~Ingredient() {}
void Ingredient::print() const {
    std::cout << "  - " << name << ": " << std::fixed << std::setprecision(2)
        << volume << " ед." << std::endl;
}

void Ingredient::printList(const std::vector<Ingredient>& ingredients,
    const std::string& title) {
    std::cout << "\n" << title << std::endl;
    if (ingredients.empty()) {
        std::cout << "  (список пуст)" << std::endl;
        return;
    }

    for (const auto& ing : ingredients) {
        ing.print();
    }
}