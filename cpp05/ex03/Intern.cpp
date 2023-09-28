#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	// std::cout << "<Intern> default Constructor called" << std::endl;
}

Intern::Intern(const Intern &obj) {
	*this = obj;
	// std::cout << "Intern Copy Constructor called" << std::endl; 
}

Intern::~Intern() {
	// std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &obj) {
	// std::cout << "Copy Assignmnet Operator called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

static AForm *newShrubbery(const std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm *newPresidential(const std::string target) {
	return new PresidentialPardonForm(target);
}

static AForm *newRobotomy(const std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	typedef AForm *(*funcPtr)(std::string target);
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	funcPtr funcArray[3] = {&newShrubbery, &newRobotomy, &newPresidential};

	for (int i = 0; i < 3; i++) {
		if (forms[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return(funcArray[i](target));
		}
	}
	std::cout << "Intern can't create " << name << std::endl;
	return NULL;
}
