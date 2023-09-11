#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        std::string getName() const;
        int getGrade() const;
        class GradeTooHighException : public std::exception {
            public:
                const char * what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char * what(void) const throw();
        };
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        void increaseGrade();
        void decresaeGrade();
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif