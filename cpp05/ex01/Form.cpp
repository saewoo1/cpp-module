#include "Form.hpp"

Form::~Form() {
    std::cout << "destructor called" << std::endl;
}

Form::Form(const Form &obj)
{
}

Form &Form::operator=(const Form &obj)
{
    // TODO: insert return statement here
}

Form::Form() {
    // 걍 뒀던가..?
}

Form::Form(const Form &obj) : name(obj.getName()), signed(obj.getSigned()), signGrade(obj.getSignGrade()), executeGrade(obj.getExecuteGrade()) {
}

const char * Form::GradeTooHighException::what(void) const throw() {
    return "Grade too High";
}

const char * Form::GradeTooLowException::what(void) const throw() {
    return "Grade too Low";
}