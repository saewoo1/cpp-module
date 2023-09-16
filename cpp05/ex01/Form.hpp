#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

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
        Form(std::string name, int signGrade, int executeGrade);

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

        void checkGrade(int grade);

        std::string getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        //form의 sign을 true. 조건은 관료의 grade가 form보다 같거나 높다면
        //grade가 너무 낮다면, Form의 lowexception을 던지자.
        void beSigned(const Bureaucrat &obj);

};

std::ostream& operator<<(std::ostream &out, const Form &obj);

#endif