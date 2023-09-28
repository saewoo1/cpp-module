#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("presiendtial form", "none", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
							: AForm("presidential form", target, 25, 5) {
	// std::cout << "Presidential Pardon Form created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj) {
	// std::cout << "Copy Presidential Form created!!!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << "Presidential Form destroyed..." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	// std::cout << "Presidential Pardon form assignment operator" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &obj) const {
	if (obj.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else if (this->getSign() == false) {
		throw NotSigned();
	}
	std::cout << this->getTarget() << " has been pardoned by president " << std::endl;
}