#include <string>
#include "Product.hpp"
#include <algorithm>
Product::Product() {};
Product::Product(std::string name, std::string description, int expirationdate, size_t price, std::string place, std::vector <std::string> structure)
{
	Name = name;
	Description = description;
	ExpirationDate = expirationdate;
	Price = price;
	Place = place;
	Structure = structure;
}
Product::Product(const Product& other)
{
	Name = other.Name;
	Description = other.Description;
	ExpirationDate = other.ExpirationDate;
	Price = other.Price;
	Place = other.Place;
	Structure = other.Structure;
}
Product::~Product() {}

Product& Product::operator=(const Product& other) {
	if (this != &other) {
		Name = other.Name;
		Description = other.Description;
		ExpirationDate = other.ExpirationDate;
		Price = other.Price;
		Place = other.Place;
		Structure = other.Structure;
	}
	return *this;
}
Product Product::operator+(const Product& other) const {
	Product result;

	result.Name = this->Name + " & " + other.Name;
	result.Description = this->Description + " " + other.Description;
	result.ExpirationDate = std::min(this->ExpirationDate, other.ExpirationDate);
	result.Price = static_cast<size_t>((this->Price + other.Price) * 0.9);
	result.Place = this->Place + " / " + other.Place;

	std::vector<std::string> newStructure;

	for (const auto& item : this->Structure) {
		bool alreadyAdded = false;
		for (const auto& added : newStructure) {
			if (item == added) {
				alreadyAdded = true;
				break;
			}
		}
		if (!alreadyAdded) {
			newStructure.push_back(item);
		}
	}

	for (const auto& item : other.Structure) {
		bool alreadyAdded = false;
		for (const auto& added : newStructure) {
			if (item == added) {
				alreadyAdded = true;
				break;
			}
		}
		if (!alreadyAdded) {
			newStructure.push_back(item);
		}
	}

	result.Structure = newStructure;

	return result;
}
Product& Product::operator-(const Product& other) const {
	Product result = *this;

	result.Name = "выбор " + this->Name + " без " + other.Name;
	result.Price = static_cast<size_t>(this->Price * 0.9);
	result.ExpirationDate = std::max(0, this->ExpirationDate - 2);

	std::vector<std::string> newStructure;

	for (const auto& item : this->Structure) {
		bool inOther = false;
		for (const auto& otherItem : other.Structure) {
			if (item == otherItem) {
				inOther = true;
				break;
			}
		}

		if (!inOther) {
			bool alreadyAdded = false;
			for (const auto& added : newStructure) {
				if (item == added) {
					alreadyAdded = true;
					break;
				}
			}
			if (!alreadyAdded) {
				newStructure.push_back(item);
			}
		}
	}

	newStructure.push_back("консервант Т1000");
	result.Structure = newStructure;

	return result;
}
Product& Product::operator-=(const Product& other) {
	if (this != &other) {

		this->Name = "выбор " + this->Name + " без " + other.Name;

		this->Price = static_cast<size_t>(this->Price * 0.9);

		this->ExpirationDate = std::max(0, this->ExpirationDate - 2);

		std::vector<std::string> newStructure;

		for (const auto& item : this->Structure) {
			bool inOther = false;
			for (const auto& otherItem : other.Structure) {
				if (item == otherItem) {
					inOther = true;
					break;
				}
			}

			if (!inOther) {
				newStructure.push_back(item);
			}
		}
		newStructure.push_back("консервант Т1000");

		this->Structure = newStructure;
	}
	return *this;
}
void Product::GetName() const { std::cout << Name << std::endl; }
void Product::GetDescription() const { std::cout << Description << std::endl; }
void Product::GetExpirationDate() const { std::cout << ExpirationDate << " days" << std::endl; }
void Product::GetPrice() const { std::cout << Price << std::endl; }
void Product::GetPlace() const { std::cout << Place << std::endl; }

void Product::GetAll() const {
	std::cout << "\n========== PRODUCT ==========" << std::endl;
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Description: " << Description << std::endl;
	std::cout << "Expiration: " << ExpirationDate << " days" << std::endl;
	std::cout << "Price: " << Price << std::endl;
	std::cout << "Place: " << Place << std::endl;
	std::cout << "Structure: ";
	for (const auto& item : Structure) {
		std::cout << item << " ";
	}
	std::cout << "\n==============================" << std::endl;
}

void Product::SetPrice(size_t UserPrice)
{
	Price = UserPrice;
}

void Product::SetAll(std::string UserName, std::string UserDescription, int UserExpirationDate, size_t UserPrice, std::string UserPlace, std::vector <std::string> UserStructure)
{
	Name = UserName;
	Description = UserDescription;
	ExpirationDate = UserExpirationDate;
	Price = UserPrice;
	Place = UserPlace;
	Structure = UserStructure;
}
void Product::SetExpirationDate(int Days)
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
int main() {
	setlocale(LC_ALL, "Russian");
	Product Milk;
	Product Bread("Bread", "Tasty Bread", 5, 47, "Svetlogorsk", { "ktr" });
	Product Eggs = Bread;

	std::cout << "=== ТЕСТ 1: Оператор + ===" << std::endl;
	Product Combined = Bread + Eggs;
	Combined.GetAll();

	std::cout << "\n=== ТЕСТ 2: Оператор - ===" << std::endl;
	Product Subtracted = Bread - Eggs;
	Subtracted.GetAll();

	std::cout << "\n=== ТЕСТ 3: Оператор -= ===" << std::endl;
	Product Test = Bread;
	Test -= Eggs;
	Test.GetAll();

	Bread.GetName();
	Bread.GetDescription();
	Bread.GetExpirationDate();
	Bread.GetPrice();
	Bread.GetPlace();
	Bread.GetAll();
	Eggs.GetAll();
}