#include "easyfind.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

int main() {
    std::vector<int> v;
    std::deque<int> d;
    std::list<int> l;

    // 각각의 컨테이너에 0 ~ 10 넣어두기
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
        d.push_back(i);
        l.push_back(i);
    }

    // 구현한 easyfind는 container와 찾을 val을 넣으면 해당 val의 idx를 반환한다.
    try {
        std::cout << *(easyfind(v, 4)) << " is at "
                << std::distance(v.begin(), easyfind(v, 4)) << std::endl;
    }catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << *(easyfind(d, 0)) << " is at "
                << std::distance(d.begin(), easyfind(d, 0)) << std::endl;
    }catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << *(easyfind(l, 99)) << " is at "
                << std::distance(l.begin(), easyfind(l, 99)) << std::endl;
    }catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}