#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error : bad argument count" << std::endl;
		return 1;
	}
	std::stack<int> stack;
	std::string expression = av[1];
	if (fillStack(expression, stack))
		return (2);
	return (0);
}