#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy form", "none", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "robotomy form destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy form", target, 72, 45) {
	std::cout << "robotomy request form created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) 
					: AForm(obj.getName(), obj.getTarget(), obj.getSignGrade(), obj.getExecuteGrade()) {
	*this = obj;
	std::cout << "copy robotomy form created" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	std::cout << "Robotomy Form assignment operator" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

void RobotomyRequestForm::executeAction(const Bureaucrat &bureaucrat) const {
	if (bureaucrat.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSign() == false) {
		std::cout << "RobotomyRequestForm couldn't be executed by " << bureaucrat.getName();
		throw NotSigned();
	}
	else {
		std::srand(std::time(NULL));

		std::cout << "*--- Loud drill noises ---*"<< std::endl;

		if (random() % 2 == 0) 
			std::cout << this->getTarget() << " successfully robotomized" << std::endl;
		else
			std::cout << this->getTarget() << " failed when trying to robotimize" << std::endl;
	}
}