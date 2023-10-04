#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 3) {
        std::cout << "Error: invalid number of argumnets" << std::endl;
        return (0);
    }

    try
    {
        PmergeMe test;
        test.merge(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}