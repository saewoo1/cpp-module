#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        try {
            Form test("hihi", 199, 45);

        } catch(const std::exception &e) {
            std::cerr << e.what() << '\n';
        }

        try {
            Form test2("byebye", 24, 0);

        } catch(const std::exception &e) {
            std::cerr << e.what() << '\n';
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
        std::cerr << e.what() << '\n';
    }
    return (0);
}
/*
signForm 함수 내에서 beSigned 함수를 호출하도록 만들고, 
이와 같은 과정을 signForm 함수 내에서 try-catch로 묶어서 결과까지 출력하도록 만들면 
main 함수에서 많은 코드들을 아낄 수 있다.
*/