#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", "none", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery creation", target, 145, 137) {
	std::cout<< "Shrubbery Creation form created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "deleted shrubbery form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj.getName(), obj.getTarget(), obj.getSignGrade(), obj.getExecuteGrade()) {
	*this = obj;
	std::cout << "Copy shrubbery form created!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	std::cout << "Shrubbery Creation Form assignment operator" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &obj) const {
	if (obj.getGrade() > this->getExecuteGrade()) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (this->getSign() == false) {
		std::cout << "Shrubbery form couldn't be executed by " << obj.getName();
		throw NotSigned();
	}
	else {
		std::ofstream out;

		out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
		if (!out.good())
			std::cerr << "Error while opening..." << std::endl;


		out<<
			"              * *\n"
			"           *    *  *\n"
			"      *  *    *     *  *\n"
			"     *     *    *  *    *\n"
			" * *   *    *    *    *   *\n"
			" *     *  *    * * .#  *   *\n"
			" *   *     * #.  .# *   *\n"
			"  *     \"#.  #: #\" * *    *\n"
			" *   * * \"#. ##\"       *\n"
			"   *       \"###\n"
			"             \"##\n"
			"              ##.\n"
			"              .##:\n"
			"              :###\n"
			"              ;###\n"
			"            ,####.\n"
			"/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n";

		out.close();
	}
}
