#pragma once

#include <string>
#include <vector>
#include "Product.hpp"

class Commission {
private:
    std::string address;
    std::vector<std::string> bannedIngredients;
    int inspectionDate;

public:
    // Конструкторы
    Commission();
    Commission(const std::string& address);
    Commission(const std::string& address,
        const std::vector<std::string>& bannedIngredients,
        int inspectionDate);
    Commission(const Commission& other);

    // Операторы
    Commission& operator=(const Commission& other);

    // Деструктор
    ~Commission();

    // Геттеры
    std::string getAddress() const;
    std::vector<std::string> getBannedIngredients() const;
    int getInspectionDate() const;

    // Сеттеры
    void setAddress(const std::string& address);
    void setBannedIngredients(const std::vector<std::string>& banned);
    void addBannedIngredient(const std::string& ingredient);
    void setInspectionDate(int date);

    bool checkProduct(const Product& product) const;

    void print() const;                
    void printFull() const;                 
    void printBannedIngredients() const;    

    static void printList(const std::vector<Commission>& commissions,
        const std::string& title = "Список комиссий:");
    static void printComparison(const Commission& c1, const Commission& c2);
};