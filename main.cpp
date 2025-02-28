#include "Store.h"
#include "Product.h"
#include "Customer.h"
#include "Exceptions.h"

int main() {

    Product* apple = new Product("Apple", 10.0);
    Product* banana = new Product("Banana", 5.0);

    Store* storeA = new Store("Store A");
    storeA->addProduct(apple, 100);
    storeA->addProduct(banana, 50);

    Store* storeB = new Store("Store B");
    storeB->addProduct(apple, 80);
    storeB->addProduct(banana, 70);

    Customer* customer1 = new Customer("John Doe", 200.0);

    try {
        customer1->buyProduct(storeA, apple, 20);
        customer1->buyProduct(storeB, banana, 30);
    }
    catch (NotEnoughMoneyException& e) {
        std::cerr << "Ошибка: недостаточно денег для покупки." << std::endl;
    }
    catch (OutOfStockException& e) {
        std::cerr << "Ошибка: товар отсутствует на складе." << std::endl;
    }

    std::vector<Store*> stores = { storeA, storeB };
    auto minPriceStore = *std::min_element(stores.begin(), stores.end(),
        [apple](const Store* s1, const Store* s2) {
            return s1->getPrice(apple) < s2->getPrice(apple);
        });
    std::cout << "Минимальная цена на яблоко в магазине: "
        << minPriceStore->name << std::endl;

    delete apple;
    delete banana;
    delete storeA;
    delete storeB;
    delete customer1;

    return 0;
}
