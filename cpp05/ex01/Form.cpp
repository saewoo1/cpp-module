#include "Form.hpp"

Form::~Form() {
    std::cout << "destructor called" << std::endl;
}

Form::Form(): sign(false), signGrade(0), executeGrade(0) {
}

Form::Form(const Form &obj) : name(obj.getName()), sign(false), signGrade(obj.getSignGrade()), executeGrade(obj.getExecuteGrade()) {
    checkGrade(obj.getExecuteGrade());
    checkGrade(obj.getSignGrade());
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), executeGrade(executeGrade) {
    checkGrade(signGrade);
    checkGrade(executeGrade);
}

Form &Form::operator=(const Form &obj) {
    if (this != &obj) {
        const_cast<std::string&>(this->name) = obj.getName();
        const_cast<int&>(this->signGrade) = obj.getSignGrade();
        const_cast<int&>(this->executeGrade) = obj.getExecuteGrade();
        this->sign = obj.getSign();
    }
    return (*this);
}

void Form::checkGrade(int grade) {
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}


const char * Form::GradeTooHighException::what(void) const throw() {
    return "<Form> Grade too High";
}

const char * Form::GradeTooLowException::what(void) const throw() {
    return "<Form> Grade too Low";
}

const char * Form::AlreadySigned::what(void) const throw() {
    return "<Form> already signed";
}

std::string Form::getName() const {
    return this->name;
}

int Form::getSignGrade() const {
    return this->signGrade;
}

int Form::getExecuteGrade() const {
    return this->executeGrade;
}

/*
요구 성적보다 높다면, sign -> true로 변환.
*/
void Form::beSigned(const Bureaucrat &obj)
{
    if (this->sign == true) 
        throw AlreadySigned();
    if (this->getSignGrade() < obj.getGrade())
        throw GradeTooLowException();
    this->sign = true;
}

bool Form::getSign() const {
    return this->sign;
}

std::ostream& operator<<(std::ostream &out, const Form &obj) {
    out << obj.getName() << " Form sign is " << std::boolalpha << obj.getSign() 

        << ", signGrade : " << obj.getSignGrade() 
        << ", executeGrade : " << obj.getExecuteGrade()
        << std::endl;

    return out;
}