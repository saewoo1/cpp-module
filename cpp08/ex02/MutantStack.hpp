#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

//iterator 기능이 없는 container stack을 상속받아 iterator 기능을 추가해주자.
template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {};
        MutantStack(const MutantStack &obj) { *this = obj; };
        MutantStack& operator=(const MutantStack &obj) { *this = obj; return (*this);};
        ~MutantStack() {};

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin() {return this->c.begin();};
        iterator end() {return this->c.end();};

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() {return this->c.rbegin();};
        reverse_iterator rend() {return this->c.rend();};

        typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
        const_iterator cbegin() {return this->c.cbegin();};
        const_iterator cend() {return this->c.cend();};

        typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator crbegin() {return this->c.crbegin();};
        const_reverse_iterator crend() {return this->c.crend();};

};

#endif