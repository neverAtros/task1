#ifndef STORE_H
#define STORE_H

#include <string>
#include <map>
#include "Product.h"
#include "Customer.h"

class Store {
private:
    std::string name;
    std::map<Product*, int> inventory;
public:
    Store(const std::string& name);
    void addProduct(Product* product, int quantity);
    bool hasProduct(const Product* product) const;
    int getQuantity(const Product* product) const;
    double getPrice(const Product* product) const;
    void sellProduct(Customer* customer, Product* product, int quantity);
};

#endif
