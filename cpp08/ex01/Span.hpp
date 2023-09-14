#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <iterator>

class Span {
    private:
        // Span();
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span(unsigned int n);
        virtual ~Span();
        Span(const Span &obj);
        Span& operator=(const Span &obj);


        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);  
        
};

#endif