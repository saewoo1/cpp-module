#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void) {
    std::srand(time(NULL));
    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
            std::cout << "generated A class !" << std::endl;
            return new A;
        case 1:
            std::cout << "generated B class !" << std::endl;
            return new B;
        case 2:
            std::cout << "generated C calss !" << std::endl;
            return new C;
    }
    std::cout << "can't generate class....." << std::endl;
    return NULL;
}

//포인터 - 참조형 둘이 반환값이 다름
void identify(Base* p) {
        if (dynamic_cast<A*>(p) != NULL) {
            std::cout << "pointer is A!" << std::endl;
        } else if (dynamic_cast<B*>(p) != NULL) {
            std::cout << "pointer is B!" << std::endl;
        } else if (dynamic_cast<C*>(p) != NULL) {
            std::cout << "pointer is C!" << std::endl;
        } else {
            std::cout << "can't identify... "<< std::endl;
        }
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "reference is A" << std::endl;
        static_cast<void>(a);
    } catch(std::exception &e) {
    } 
    
    try {
        B &b = dynamic_cast<B&>(p);
        std::cout << "reference is B" << std::endl;
        static_cast<void>(b);
    } catch(std::exception &e) {
    }

    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << "reference is C" << std::endl;
        static_cast<void>(c);
    } catch(std::exception &e) {
    }

}

// void leak() {
//     system("leaks base");
// }
int main() {

    // atexit(leak);
    Base *obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;

    return (0);

}