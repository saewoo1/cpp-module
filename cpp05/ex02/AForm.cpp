#include "AForm.hpp"

AForm::~AForm() {
    std::cout << "destructor called" << std::endl;
}

AForm::AForm(): _name("form"), _target("default"), _sign(false), _signGrade(150), _executeGrade(150) {
}

AForm::AForm(const AForm &obj) 
        : _name(obj.getName()),
         _target(obj.getTarget()),
         _sign(false),
         _signGrade(obj.getSignGrade()),
         _executeGrade(obj.getExecuteGrade()) {
    checkGrade(obj.getExecuteGrade());
    checkGrade(obj.getSignGrade());
    std::cout << "copy Form created!" << std::endl;
}

AForm::AForm(const std::string name, const std::string target, int signGrade, int executeGrade) 
                : _name(name), 
                _target(target),
                _sign(false),
                _signGrade(signGrade),
                _executeGrade(executeGrade) {
    checkGrade(signGrade);
    checkGrade(executeGrade);
    std::cout << "correct Form created!" << std::endl;
}

AForm &AForm::operator=(const AForm &obj) {
    if (this != &obj) {
        const_cast<std::string&>(_name) = obj.getName();
        const_cast<int&>(_signGrade) = obj.getSignGrade();
        const_cast<int&>(_executeGrade) = obj.getExecuteGrade();
        _sign = obj.getSign();
    }
    return (*this);
}

void AForm::checkGrade(int grade) {
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}


const char * AForm::GradeTooHighException::what(void) const throw() {
    return "<AForm> Grade too High";
}

const char * AForm::GradeTooLowException::what(void) const throw() {
    return "<AForm> Grade too Low";
}

const char * AForm::AlreadySigned::what(void) const throw() {
    return "<AForm> already signed";
}

const char * AForm::NotSigned::what(void) const throw() {
    return "<AForm> not signed";
}

const std::string& AForm::getName() const {
    return _name;
}

const std::string& AForm::getTarget() const {
    return _target;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

/*
요구 성적보다 높다면, sign -> true로 변환.
*/
void AForm::beSigned(const Bureaucrat &obj)
{
    if (_sign == true) 
        throw AlreadySigned();
    if (this->getSignGrade() < obj.getGrade())
        throw GradeTooLowException();
    _sign = true;
}

void AForm::beExecuted(const Bureaucrat &person) const {
    if (_sign == false) {
        std::cout << person.getName() << " can't execute " << _name << std::endl;
        throw NotSigned();
    }
    if (_executeGrade < person.getGrade()) {
        std::cout << person.getName() << " can't execute " << _name << std::endl;
        throw GradeTooLowException();
    }

    std::cout << person.getName() << " has executed " << _name << std::endl;
    this->execute(person);

}

bool AForm::getSign() const {
    return _sign;
}

std::ostream& operator<<(std::ostream &out, const AForm &obj) {
    out << obj.getName() << " AForm sign is " << std::boolalpha << obj.getSign() 

        << ", signGrade : " << obj.getSignGrade() 
        << ", executeGrade : " << obj.getExecuteGrade()
        << std::endl;

    return out;
}