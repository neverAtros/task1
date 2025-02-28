#include "Customer.h"
#include "Exceptions.h"

Customer::Customer(const std::string& name, double initialBalance) : name(name), balance(initialBalance) {}

void Customer::buyProduct(Store* store, Product* product, int quantity) {
    store->sellProduct(this, product, quantity);
}

double Customer::getBalance() const {
    return balance;
}

void Customer::setBalance(double newBalance) {
    balance = newBalance;
}