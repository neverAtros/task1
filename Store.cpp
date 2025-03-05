#include "Store.h"
#include "Exceptions.h"

Store::Store(const std::string& name) : name(name) {}

void Store::addProduct(Product* product, int quantity) {
    inventory[product] += quantity;
}

bool Store::hasProduct(const Product* product) const {
    return inventory.find(product) != inventory.end();
}

int Store::getQuantity(const Product* product) const {
    if (!hasProduct(product)) {
        return 0;
    }
    return inventory.at(product);
}

double Store::getPrice(const Product* product) const {
    return product->getPrice();
}

void Store::sellProduct(Customer* customer, Product* product, int quantity) {
    if (inventory[product] < quantity) {
        throw OutOfStockException("Товар отсутствует на складе.");
    }
    double totalCost = product->getPrice() * quantity;
    if (customer->getBalance() < totalCost) {
        throw NotEnoughMoneyException("Недостаточно денег для покупки.");
    }
    customer->setBalance(customer->getBalance() - totalCost);
    inventory[product] -= quantity;
}
