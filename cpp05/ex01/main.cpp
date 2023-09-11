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
/*
signForm 함수 내에서 beSigned 함수를 호출하도록 만들고, 
이와 같은 과정을 signForm 함수 내에서 try-catch로 묶어서 결과까지 출력하도록 만들면 
main 함수에서 많은 코드들을 아낄 수 있다.
*/