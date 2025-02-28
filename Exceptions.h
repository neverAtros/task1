#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class NotEnoughMoneyException : public std::runtime_error {
public:
    NotEnoughMoneyException(const std::string& message) : std::runtime_error(message) {}
};

class OutOfStockException : public std::runtime_error {
public:
    OutOfStockException(const std::string& message) : std::runtime_error(message) {}
};

#endif