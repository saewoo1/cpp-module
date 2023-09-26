#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", "none", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery creation", target, 145, 137) {
	// std::cout<< "Shrubbery Creation form created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "deleted shrubbery form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj) {
	// std::cout << "Copy shrubbery form created!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	// std::cout << "Shrubbery Creation Form assignment operator" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &obj) const {
	if (obj.getGrade() > this->getExecuteGrade()) {
		throw GradeTooLowException();
	}
	else if (this->getSign() == false)
		throw NotSigned();
	else {
		std::ofstream out;

		out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
		if (!out.good())
			std::cout << "Error while opening..." << std::endl;

		out<<
			"cpp05/ \n"
			"├─ ex00/ \n"
			"│  ├─ Bureaucrat.cpp \n"
			"│  ├─ Bureaucrat.hpp \n"
			"│  ├─ main.cpp \n"
			"│  ├─ Makefile \n"
			"├─ ex01/ \n"
			"│  ├─ Bureaucrat.cpp \n"
			"│  ├─ Bureaucrat.hpp \n"
			"│  ├─ Form.cpp\n"
			"│  ├─ Form.hpp\n"
			"│  ├─ main.cpp\n"
			"│  ├─ Makefile\n"
			"├─ ex02/\n"
			"│  ├─ AForm.cpp\n"
			"│  ├─ AForm.hpp\n"
			"│  ├─ Bureaucrat.cpp\n"
			"│  ├─ Bureaucrat.hpp\n"
			"│  ├─ main.cpp\n"
			"│  ├─ Makefile\n"
			"│  ├─ PresidentialPardonForm.cpp\n"
			"│  ├─ PresidentialPardonForm.hpp\n"
			"│  ├─ RobotomyRequestForm.cpp\n"
			"│  ├─ RobotomyRequestForm.hpp\n"
			"│  ├─ ShrubberyCreationForm.cpp\n"
			"│  ├─ ShrubberyCreationForm.hpp\n"
			"├─ ex03/\n"
			"│  ├─ AForm.cpp\n"
			"│  ├─ AForm.hpp\n"
			"│  ├─ Bureaucrat.cpp\n"
			"│  ├─ Bureaucrat.hpp\n"
			"│  ├─ Intern.cpp\n"
			"│  ├─ Intern.hpp\n"
			"│  ├─ main.cpp\n"
			"│  ├─ Makefile\n"
			"│  ├─ PresidentialPardonForm.cpp\n"
			"│  ├─ PresidentialPardonForm.hpp\n"
			"│  ├─ RobotomyRequestForm.cpp\n"
			"│  ├─ RobotomyRequestForm.hpp\n"
			"│  ├─ ShrubberyCreationForm.cpp\n"
			"│  ├─ ShrubberyCreationForm.hpp\n";

		out.close();
	}
}
