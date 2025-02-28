#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Store.h"
#include "Product.h"

class Customer {
private:
    std::string name;
    double balance;
public:
    Customer(const std::string& name, double initialBalance = 0.0);
    void buyProduct(Store* store, Product* product, int quantity);
    double getBalance() const;
    void setBalance(double newBalance);
};

#endif
