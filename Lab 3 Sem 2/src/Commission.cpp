#include "Commission.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

Commission::Commission() : address(""), inspectionDate(0) {}

Commission::Commission(const std::string& address)
    : address(address), inspectionDate(0) {
}

Commission::Commission(const std::string& address,
    const std::vector<std::string>& bannedIngredients,
    int inspectionDate)
    : address(address), bannedIngredients(bannedIngredients),
    inspectionDate(inspectionDate) {
}

Commission::Commission(const Commission& other)
    : address(other.address),
    bannedIngredients(other.bannedIngredients),
    inspectionDate(other.inspectionDate) {
}

Commission& Commission::operator=(const Commission& other) {
    if (this != &other) {
        address = other.address;
        bannedIngredients = other.bannedIngredients;
        inspectionDate = other.inspectionDate;
    }
    return *this;
}

Commission::~Commission() {}

std::string Commission::getAddress() const { return address; }
std::vector<std::string> Commission::getBannedIngredients() const {
    return bannedIngredients;
}
int Commission::getInspectionDate() const { return inspectionDate; }

void Commission::setAddress(const std::string& addr) { address = addr; }
void Commission::setBannedIngredients(const std::vector<std::string>& banned) {
    bannedIngredients = banned;
}
void Commission::addBannedIngredient(const std::string& ingredient) {
    for (const auto& item : bannedIngredients) {
        if (item == ingredient) return;
    }
    bannedIngredients.push_back(ingredient);
}
void Commission::setInspectionDate(int date) { inspectionDate = date; }

bool Commission::checkProduct(const Product& product) const {
    for (const auto& banned : bannedIngredients) {
        if (product.hasIngredient(banned)) {
            std::cout << " Товар НЕЛЕГАЛЕН: содержит запрещенный ингредиент '"
                << banned << "'" << std::endl;
            return false;
        }
    }

    if (product.isExpired(inspectionDate)) {
        std::cout << " Товар НЕЛЕГАЛЕН: срок годности истек (проверка: день "
            << inspectionDate << ", срок: " << product.getExpirationDate()
            << " дней)" << std::endl;
        return false;
    }

    std::cout << " Товар ЛЕГАЛЕН: все проверки пройдены" << std::endl;
    return true;
}

void Commission::print() const {
    std::cout << "  Комиссия по адресу: " << address
        << " | Дата проверки: день " << inspectionDate
        << " | Запрещено: " << bannedIngredients.size() << " ингр." << std::endl;
}

void Commission::printFull() const {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "        ПОЛНАЯ ИНФОРМАЦИЯ О КОМИССИИ" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    std::cout << " Адрес: " << address << std::endl;
    std::cout << " Дата проверки: день " << inspectionDate << std::endl;

    printBannedIngredients();

    std::cout << std::string(50, '=') << std::endl;
}

void Commission::printBannedIngredients() const {
    std::cout << " Запрещенные ингредиенты:" << std::endl;
    if (bannedIngredients.empty()) {
        std::cout << "  (нет запрещенных ингредиентов)" << std::endl;
        return;
    }

    for (size_t i = 0; i < bannedIngredients.size(); ++i) {
        std::cout << "  " << (i + 1) << ". " << bannedIngredients[i] << std::endl;
    }
}

void Commission::printList(const std::vector<Commission>& commissions,
    const std::string& title) {
    std::cout << "\n" << title << std::endl;
    std::cout << std::string(40, '-') << std::endl;

    if (commissions.empty()) {
        std::cout << "  (список пуст)" << std::endl;
        return;
    }

    for (size_t i = 0; i < commissions.size(); ++i) {
        std::cout << std::setw(3) << (i + 1) << ". ";
        commissions[i].print();
    }
    std::cout << std::string(40, '-') << std::endl;
    std::cout << "Всего комиссий: " << commissions.size() << std::endl;
}
