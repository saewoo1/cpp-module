#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat saewoo("saewoo", 150);
    Bureaucrat tokki("tokki", 1);

    std::cout << std::endl;

    ShrubberyCreationForm shrubbery("test");
    PresidentialPardonForm presidental("test");
    RobotomyRequestForm robotomy("test");

    std::cout << std::endl;

    tokki.executeForm(shrubbery);
    shrubbery.beSigned(tokki);
    tokki.executeForm(shrubbery);

    std::cout << std::endl;

    tokki.executeForm(presidental);
    presidental.beSigned(tokki);
    tokki.executeForm(presidental);

    std::cout << std::endl;

    tokki.executeForm(robotomy);
    robotomy.beSigned(tokki);
    tokki.executeForm(robotomy);
    std::cout << std::endl;

    try {
        saewoo.executeForm(shrubbery);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);

}