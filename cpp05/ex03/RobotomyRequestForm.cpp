#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy form", "none", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "robotomy form destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy form", target, 72, 45) {
	// std::cout << "robotomy request form created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj) {
	// std::cout << "copy robotomy form created" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	// std::cout << "Robotomy Form assignment operator" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const {
	if (bureaucrat.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	else if (this->getSign() == false) {
		throw NotSigned();
	}
	else {
		std::srand(std::time(NULL));

		std::cout << "*--- Loud drill noises ---*"<< std::endl;

		if (rand() % 2 == 0) 
			std::cout << this->getTarget() << " successfully robotomized" << std::endl;
		else
			std::cout << this->getTarget() << " failed when trying to robotimize" << std::endl;
	}
}