#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <iterator>

class Span {
    private:
        Span();
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span(unsigned int n);
        virtual ~Span();
        Span(const Span &obj);
        Span& operator=(const Span &obj);


        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);  
        
};

#endif

/*
vector -> 동적 배열
1. 크기 동적 조절 가능. 메모리 낭비, 크기 제한 걱정 줄이기
2. 연속적인 메모리. 배열과 유사하게 빠른 원소 접근 가능. 포인터, 반복자 사용하여 원소 접근 가능.
3. 벡터 원소 추가 시 용량 부족하면 자동으로 늘어남.
4. at()함수는 범위를 검사해 idx가 벡터 크기를 초과하는지 확인 가능.

span -> 연속된 블록에 대한 비소유 뷰?
특정 데이터 블록의 시작 포인터와 크기를 가리킨다. 데이터를 소유 / 관리하지 않음.
배열, 벡터, 문자열등의 연속된 데이터 조각에 대한 안전하고 효율적 접근 가능

비소유 뷰 -> 복사본을 만들지 않고도 데이터에 안전한 접근 가능.

std::span은 데이터 블록의 시작 포인터와 크기를 가진다. 이를 이용해 데이터에 접근 가능.
시작 포인터 : data(), 크기: size()

범위 기반 반복 -> 범위 기반 for 루프와 함께 연속된 데이터에 쉽게 접근 가능.

둘의 차이점은 span은 단순히 데이터 블록의 시작 포인터와 크기를 가리키는 역할만 해줌.
크기 조절에 대해서도 vector는 동적 조절이므로 제거하고 재할당하는 과정,
span은 크기 고정

*/