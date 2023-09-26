#include "Bureaucrat.hpp"

void Bureaucrat::increaseGrade() {
    if (this->grade - 1 < 1) {
        throw GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decresaeGrade() {
    if (this->grade + 1 > 150) {
        throw GradeTooLowException();
    }
    this->grade++;
}

void Bureaucrat::checkGrade() {
    if (this->grade > 150)
        throw GradeTooLowException();
    if (this->grade < 1)
        throw GradeTooHighException();
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Grade too High";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Grade too Low";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

const std::string& Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

Bureaucrat::~Bureaucrat() {
    // std::cout << "destructor is called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this != &obj) {
        const_cast<std::string&>(this->name) = obj.getName();
        this->grade = obj.getGrade();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(): name("default"), grade(150) {
    checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.getName()), grade(obj.getGrade()) {
    checkGrade();
}


std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj) {
    out << obj.getName() << " bureaucrat grade " << obj.getGrade() << std::endl;

    return out;
}

void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch(const std::exception &e) {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl; 
    }
}

void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.beExecuted(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch(std::exception &e) {
        std::cout << name << " couldn't executed " << form.getName() << " because " << e.what() << std::endl;
    }
}