#include "Span.hpp"
#include <limits>

//할당된 vector clear
Span::~Span() {
    _numbers.clear();
    std::cout << "destructor called" << std::endl;
}

Span::Span(): _maxSize(0), _numbers(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

/*
1. 복사할 vector의 시작 지점 설정
2. 생성자의 vector에 iterator 돌면서 할당해주기 
*/
Span::Span(const Span &obj) : _maxSize(obj._maxSize) {
    std::vector<int>::const_iterator iter = obj._numbers.begin();
    for (; iter < obj._numbers.end(); iter++) {
        _numbers.push_back(*iter);
    }
}

Span& Span::operator=(const Span &obj) {
    if (this != &obj) {
        std::vector<int>::const_iterator iter = obj._numbers.begin();
        _numbers.clear();
        _maxSize = obj._maxSize;
        for (; iter < obj._numbers.end(); iter++) {
            _numbers.push_back(*iter);
        }
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_numbers.size() >= _maxSize) {
        throw std::invalid_argument("span is already full!");
    }
    _numbers.push_back(n);
}

// iterator 사용해서 한번에 넣기
void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    if ((_numbers.size() >= _maxSize) 
            || (_maxSize - _numbers.size() < static_cast<unsigned int>(end - start))) {
        throw std::invalid_argument("span is already full!");
    }
    _numbers.insert(_numbers.end(), start, end);

}

// 어느 간격이 가장 크기가 작을가~
unsigned int Span::shortestSpan() const {
    
    if (_numbers.size() < 2) {
        throw std::invalid_argument("list has just one number");
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int shortest = std::numeric_limits<int>::max();
    for (unsigned int i = 1; i < sorted.size(); i++) {
        unsigned int min = sorted[i] - sorted[i - 1];
        if (min < shortest) {
            shortest = min;
        }
    }
    return (shortest);
}

// 정렬 후 마지막 data - 첫번 째 data. 
unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::invalid_argument("list has just one number");
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    return (sorted.back() - sorted.front());
}


