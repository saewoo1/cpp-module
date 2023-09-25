#ifndef BUREAUCAT_HPP
# define BUREAUCAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        const std::string& getName() const;
        int getGrade() const;

        void increaseGrade();
        void decresaeGrade();
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };

        void checkGrade();

        Bureaucrat &operator=(const Bureaucrat &obj);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();

        void signForm(Form &form) const;

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif