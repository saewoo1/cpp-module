#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Form {
    private:
        const std::string name;
        bool signed;
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

        void beSigned();

        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;


};

std::ostream& operator<<(std::ostream &out, const Form &obj);

#endif