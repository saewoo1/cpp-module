#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// void    leaks() {
//     std::system("leaks Forms");
// }

int main() {
    // std::atexit(leaks);
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