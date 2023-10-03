#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

bool isOperation(std::string &token);
bool fillStack(std::string &expression, std::stack<int> stack);


#endif