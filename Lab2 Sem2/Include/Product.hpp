#pragma once
#include <iostream>
#include <vector>
class Product
{
private:
    std::string Name;
    std::string Description;
    int ExpirationDate;
    size_t Price;
    std::string Place;
    std::vector <std::string> Structure;
public:
    Product();
    Product(std::string name, std::string description, int expirationdate, size_t price, std::string place, std::vector <std::string> a);
    Product(const Product& other);
    ~Product();
    Product& operator=(const Product& other);
    Product operator+(const Product& other) const;
    Product& operator-(const Product& other) const;
    Product& operator-=(const Product& other);
    void GetName() const;
    void GetDescription() const;
    void GetExpirationDate() const;
    void GetPrice() const;
    void GetPlace() const;
    void GetAll() const;
    void SetPrice(size_t UserPrice);
    void SetAll(std::string UserName, std::string UserDescription, int UserExpirationDate, size_t UserPrice, std::string UserPlace, std::vector <std::string> a);
    void SetExpirationDate(int Days);
};