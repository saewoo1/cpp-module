#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {

    Intern intern;

    AForm *form1 = intern.makeForm("shrubbery creation", "Form1");
    AForm *form2 = intern.makeForm("robotomy request", "Form2");
    AForm *form3 = intern.makeForm("presidential pardon", "Form3");

    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;

    delete form1;
    delete form2;
    delete form3;


    return (0);

}