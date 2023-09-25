#ifndef BUREAUCAT_HPP
# define BUREAUCAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        std::string getName() const;
        int getGrade() const;

        void increaseGrade();
        void decresaeGrade();
        
        class GradeTooHighException : public std::exception {
            public:
                const char * what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char * what(void) const throw();
        };

        void checkGrade();

        Bureaucrat &operator=(const Bureaucrat &obj);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif

/*
const_cast
type 불일치 시 인자 전달이 불가능함.
포인터 / 참조형의 const를 잠시 풀어주는데 사용하자.

*/