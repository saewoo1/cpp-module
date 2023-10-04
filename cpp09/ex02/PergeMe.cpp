#include "PergeMe.hpp"

PergeMe::PergeMe() {
    _unpairedDeq = -1;
    _unpairedVec = -1;
}

PergeMe::~PergeMe() {}

PergeMe &PergeMe::operator=(const PergeMe &obj)
{
    if (this != &obj)
        return *this;
    return *this;
}

PergeMe::PergeMe(const PergeMe &obj) {
    *this = obj;
}

void PergeMe::merge(int ac, char **av) {
    PergeMe::populateContainers(ac, av);
    PergeMe::printUnsortedSequence(ac);
    PergeMe::sortVec();
    PergeMe::sortDeq();
}

void PergeMe::populateContainers(int ac, char **av) {
    std::set<int>   numbers;

    for (int i = 1; i < ac; i++) {
        int len = std::strlen(av[i]);
        for (int j = 0; j < len; j++) {
            if (!isdigit(av[i][j]) && av[i][j] != '+')
                throw std::invalid_argument("Error: Invalid argument.");
        }

        int num = std::atoi(av[i]);
        if (num < 0)
            throw std::runtime_error("Error: Negative Numbers are invalid");
        if (!numbers.insert(num).second)
            throw std::runtime_error("Error: Duplicated number are invalid");
        _inputVec.push_back(num);
        _inputDeq.push_back(num);
    }
}

template<typename T>
void PergeMe::printSequence(const T &seq) {
    typename T::const_iterator iter;

    int i = 0;
    for (iter = seq.begin(); iter != seq.end(); ++iter) {
        std::cout << *iter << " ";
        if (i == 15) {
            std::cout << "[...]";
            break;
        }
        i++;
    }
    std::cout << std::endl;
}

void PergeMe::printUnsortedSequence(int ac) {
    std::cout << "Before: ";
    for (int i = 0; i < (ac - 1); i++) {
        std::cout << _inputVec[i] << " ";
        if (i == 15) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

int PergeMe::jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    int pre1 = 0;
    int pre2 = 1;
    int cur = 0;

    for (int i = 2; i <= n; ++i) {
        cur = pre1 + 2 * pre2;
        pre1 = pre2;
        pre2 = cur;
    }
    return cur;
}

