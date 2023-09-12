#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("presiendtial form", "none", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
							: AForm("presidential form", target, 25, 5) {
	std::cout << "Presidential Pardon Form created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) 
							: AForm(obj.getName(), obj.getTarget(), obj.getSignGrade(), obj.getExecuteGrade()) {
	*this = obj;
	std::cout << "Copy Presidential Form created!!!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Form destroyed..." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	std::cout << "Presidential Pardon form assignment operator" << std::endl;

	if (this == &obj)
		return *this;
	return *this;
}

void PresidentialPardonForm::executeAction() const {
	std::cout << this->getTarget() << " has been pardoned by presideont " << std::endl;
}