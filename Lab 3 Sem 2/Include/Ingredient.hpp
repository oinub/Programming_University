#pragma once
#include <string>
#include <iostream>
#include <vector>

struct Ingredient {
    std::string name;
    double volume;

    Ingredient();
    Ingredient(const std::string& name, double volume);
    Ingredient(const Ingredient& other);

    Ingredient& operator=(const Ingredient& other);

    bool operator==(const Ingredient& other) const;

    void print() const;

    static void printList(const std::vector<Ingredient>& ingredients,
        const std::string& title = "Indredients:");

    ~Ingredient();
};
