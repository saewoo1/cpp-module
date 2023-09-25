#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        const std::string _target;
        bool _sign;
        const int _signGrade;
        const int _executeGrade;
    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm &obj);
        AForm &operator=(const AForm &obj);
        AForm(const std::string& name, const std::string& target, int signGrade, int executeGrade);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };
        class AlreadySigned : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };
        class NotSigned : public std::exception {
            public:
                virtual const char * what(void) const throw();
        };

        void checkGrade(int grade);

        const std::string& getName() const;
        const std::string& getTarget() const;

        bool getSign() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(const Bureaucrat &obj);
        void beExecuted(const Bureaucrat &obj) const;

        virtual void execute(const Bureaucrat &obj) const = 0;
};

std::ostream& operator<<(std::ostream &out, const AForm &obj);

#endif