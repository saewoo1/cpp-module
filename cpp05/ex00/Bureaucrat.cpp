#include "Bureaucrat.hpp"

void Bureaucrat::increaseGrade() {
    int tmp;
    tmp = this->grade;
    if (tmp - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decresaeGrade() {
    int tmp;
    tmp = this->grade;
    if (tmp + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Grade too High";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Grade too Low";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "destructor is called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this != &obj) {
        const_cast<std::string&>(this->name) = obj.getName();
        this->grade = obj.getGrade();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.getName()), grade(obj.getGrade()) {
}


std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj) {
    out << obj.getName() << "bureaucrat grade" << obj.getGrade() << std::endl;

    return out;
}