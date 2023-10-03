#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "bad argument" << std::endl;
        exit(1);
    }

    BitcoinExchange test;
    if (test.fillCsv())
        return (2);
    if (test.inputValue(av[1]))
        return (3);
    return (0);
}