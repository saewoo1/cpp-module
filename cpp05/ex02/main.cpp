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


    std::cout << shrubbery << std::endl;
    std::cout << presidental << std::endl;
    std::cout << robotomy << std::endl;
    
    std::cout << std::endl;

    tokki.executeForm(shrubbery);
    tokki.signForm(shrubbery);
    tokki.executeForm(shrubbery);

    std::cout << std::endl;

    tokki.executeForm(presidental);
    tokki.signForm(presidental);
    tokki.executeForm(presidental);

    std::cout << std::endl;

    tokki.executeForm(robotomy);
    tokki.signForm(robotomy);
    tokki.executeForm(robotomy);
    std::cout << std::endl;

    try {
        saewoo.executeForm(shrubbery);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);

}