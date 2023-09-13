#include "iter.hpp"

int main() {
    int intArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::string stringArr[3] = {"hihi", "byebye", "catcat"};

    ::iter(intArr, 10, printer);
    ::iter(stringArr, 3, printer);
}