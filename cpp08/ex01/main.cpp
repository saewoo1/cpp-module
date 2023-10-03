#include "Span.hpp"
#include <ctime>
#include <algorithm>
#include <cstdlib>

int main() {
    {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    }
    const int size = 12345;
    std::vector<int> testVector(size);


    //난수 10000개 만들고 섞어서 결과값 보여주기ㅠ
    std::srand(std::time(NULL));

    for (int i = 0; i < size; i++) {
        int ranNum;
        do {
            ranNum = (std::rand() % size) + 1;
        } while (std::count(testVector.begin(), testVector.end() + i, ranNum) > 0);
        testVector[i] = ranNum;
    }

    Span sp = Span(size);

    sp.addNumbers(testVector.begin(), testVector.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}