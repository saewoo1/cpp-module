#include "Bureaucrat.hpp"

int main() {
    try {
        try {
            Bureaucrat test("hihi", 199);

        } catch(const std::exception &e) {
            std::cerr << e.what() << '\n';
        }

        // Bureaucrat test;
        Bureaucrat a("a", 150);
        Bureaucrat b("b", 150);
        Bureaucrat c("c", 1);
        Bureaucrat tmp(c);

        tmp = b;

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << tmp << std::endl;
        // std::cout << test.getName() << std::endl;
        // std::cout << test.getGrade() << std::endl;

        std::cout << "----------------------" << std::endl;

        a.increaseGrade();
        c.increaseGrade();
        std::cout << a << std::endl;
        std::cout << c << std::endl;
        b.decresaeGrade();
        std::cout << b << std::endl;
        std::cout << std::endl;

    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return (0);
}