#include "Bureaucrat.hpp"

int main() {
    try {
        try {
            Bureaucrat test("hihi", 199);

        } catch(const std::exception &e) {
            std::cerr << e.what() << '\n';
        }

        Bureaucrat a("a", 150);
        Bureaucrat b("b", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << std::endl;

        std::cout << "----------------------" << std::endl;

        a.increaseGrade();
        std::cout << a << std::endl;
        b.decresaeGrade();
        std::cout << b << std::endl;
        std::cout << std::endl;

    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return (0);
}