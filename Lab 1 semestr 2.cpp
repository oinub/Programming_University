#include <string>
#include <iostream>
class Product
{
private:
    std::string Name;
    std::string Description;
    int ExpirationDate;
    size_t Price;
    std::string Place;
public:
    Product() {};
    Product(std::string name, std::string description, int expirationdate, size_t price, std::string place)
    {
        Name = name;
        Description = description;
        ExpirationDate = expirationdate;
        Price = price;
        Place = place;
    }
    Product(const Product& other)
    {
        Name = other.Name;
        Description = other.Description;
        ExpirationDate = other.ExpirationDate;
        Price = other.Price;
        Place = other.Place;
    }
    void GetName()
    {
        std::cout << Name << std::endl;
    }
    void GetDescription()
    {
        std::cout << Description << std::endl;
    }
    void GetExpirationDate()
    {
        std::cout << ExpirationDate << std::endl;
    }
    void GetPrice()
    {
        std::cout << Price << std::endl;
    }
    void GetPlace()
    {
        std::cout << Place << std::endl;
    }
    void SetPrice(size_t UserPrice)
    {
        Price = UserPrice;
    }
    void GetAll() {
        std::cout << Name << std::endl;
        std::cout << Description << std::endl;
        std::cout << ExpirationDate << std::endl;
        std::cout << Price << std::endl;
        std::cout << Place << std::endl;
    }
    void SetAll(std::string UserName, std::string UserDescription, int UserExpirationDate, size_t UserPrice, std::string UserPlace)
    {
        Name = UserName;
        Description = UserDescription;
        ExpirationDate = UserExpirationDate;
        Price = UserPrice;
        Place = UserPlace;
    }
    void SetExpirationDate(int Days)
    {
        if (Days <= 0)
        {
            std::cout << "Error! " << std::endl;
        }
        ExpirationDate = ExpirationDate - Days;
        if (ExpirationDate <= 0)
        {
            ExpirationDate = 0;
            std::cout << "Product expired!" << std::endl;
        }
        std::cout << "New shelf life: " << ExpirationDate << " days" << std::endl;
    }
    ~Product() {};
};
int main() {
    Product Milk();
    Product Bread("Bread", "Tasty Bread", 5, 47, "Svetlogorsk");
    Product Eggs = Bread;
    Bread.GetName();
    Bread.GetDescription();
    Bread.GetExpirationDate();
    Bread.GetPrice();
    Bread.GetPlace();
    Bread.GetAll();
    Eggs.GetAll();
}
