#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

//iterator 기능이 없는 container stack을 상속받아 iterator 기능을 추가해주자.
template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack<T>();
        MutantStack<T>(const MutantStack &obj);
        MutantStack& operator=(const MutantStack &obj);
        ~MutantStack<T>();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() {
            return (this->c.begin());
        }
        iterator end() {
            return (this->c.end());
        }
};

template <typename T>
MutantStack<T>::MutantStack(void) {
    // std::cout << "MutantStack default constructor " << std::endl;
    return ;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &obj) {
    if (this != &obj)
        *this = obj;
    // std::cout << "Copy constructor called" << std::endl;
    return ;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
    return ;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &obj) {
    (void)obj;
    return *this;
}

#endif