#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int executeGrade;
    public:
        Form();
        ~Form();
        Form(const Form &obj);
        Form &operator=(const Form &obj);

        class GradeTooHighException : public std::exception {
            public:
                const char * what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char * what(void) const throw();
        };
        class AlreadySigned : public std::exception {
            public:
                const char * what(void) const throw();
        };

        void checkGrade(int signGrade, int executeGrade);

        std::string getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat &obj);

};

std::ostream& operator<<(std::ostream &out, const Form &obj);

#endif