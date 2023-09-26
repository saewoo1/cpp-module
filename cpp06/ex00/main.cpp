#include "Scalar.hpp"

int main(int ac, char **av) {

	(void)av;
	if (ac == 2) {
		Scalar::convertAll(av[1]);
		return (0);
	}
	else
		std::cout << "Wrong Argument count" << std::endl;
	return (0);
}