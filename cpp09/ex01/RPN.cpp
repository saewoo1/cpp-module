#include "RPN.hpp"

bool isOperation(std::string &token) {
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return true;
	return false;
}

void printStack(std::stack<int> stack) {
	std::stack<int> tmpStack = stack;
	if (tmpStack.size() != 1){
		std::cout << "invalid argument count.." << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}


bool exeOperation(std::string token, std::stack<int> &stack) {
	if (stack.size() <= 1) {
		std::cout << "Not enough numbers to operate with " << token << std::endl;
		return true;
	}
	int	n2 = stack.top();
	stack.pop();
	int	n1 = stack.top();
	stack.pop();

	if (token == "+")
		stack.push(n1 + n2);
	else if (token == "-")
		stack.push(n1 - n2);
	else if (token == "*")
		stack.push(n1 * n2);
	else if (token == "/") {
		if (n2 == 0) {
			std::cout << "Can't divide by 0 ! " << std::endl;
			return true;
		}
		stack.push(n1 / n2);
	}
	return false;
}

bool fillStack(std::string &expression, std::stack<int> stack) {
	std::istringstream iss(expression);
	std::string	token;

	while (iss >> token) {
		if (token.size() != 1 || (!std::isdigit(token[0]) && !isOperation(token))) {
			std::cout << "Invalid input : " << token << std::endl;
			return true;
		}
		else if (std::isdigit(token[0]))
			stack.push(token[0] - '0');
		else if (isOperation(token))
			if (exeOperation(token, stack))
				return (1);
	}
	printStack(stack);
	return (0);
}