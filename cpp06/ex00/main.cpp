#include "Scalar.hpp"

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "please input param!" << std::endl;
	}

	Scalar::ScalarConverter(av[1]);

	return (0);
}