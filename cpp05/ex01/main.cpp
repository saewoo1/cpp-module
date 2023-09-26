#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        try {
            Form test("hihi", 199, 45);

        } catch(const std::exception &e) {
            std::cout << e.what() << '\n';
        }

        try {
            Form test2("byebye", 24, 0);

        } catch(const std::exception &e) {
            std::cout << e.what() << '\n';
        }

        Bureaucrat sohyupar("sohyupar", 120);
        Form a("FormA", 150, 44);
        Form b("FormB", 119, 140);

        std::cout << sohyupar << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;

        sohyupar.signForm(a);
        sohyupar.signForm(b);

    } catch(const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return (0);
}
