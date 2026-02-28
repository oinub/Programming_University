#pragma once
#include <string>
#include <vector>
#include "Ingredient.hpp"

class Product {
private:
    std::string name;
    std::string description;
    int expirationDate;
    size_t price;
    std::string place;
    std::vector<Ingredient> ingredients;

public:
    Product();
    Product(const std::string& name, const std::string& description,
        int expirationDate, size_t price, const std::string& place,
        const std::vector<Ingredient>& ingredients);
    Product(const Product& other);

    Product& operator=(const Product& other);
    Product operator+(const Product& other) const;
    Product operator-(const Product& other) const;
    Product& operator-=(const Product& other);

    ~Product();

    std::string getName() const;
    std::string getDescription() const;
    int getExpirationDate() const;
    size_t getPrice() const;
    std::string getPlace() const;
    std::vector<Ingredient> getIngredients() const;

    bool hasIngredient(const std::string& ingredientName) const;
    bool isExpired(int currentDate) const;

    void setPrice(size_t newPrice);
    void setExpirationDate(int days);

    void print() const;                    
    void printFull() const;                
    void printIngredients() const;          
    void printExpirationStatus(int currentDate) const; 

    static void printList(const std::vector<Product>& products,
        const std::string& title = "Список продуктов:");
    static void printComparison(const Product& p1, const Product& p2);
};