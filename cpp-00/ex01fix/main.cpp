#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook pages;
	std::string command;

	std::cout << "Select Command! : EXIT / ADD / SEARCH" << std::endl;
	while (getline(std::cin, command))
	{
		if (command == "EXIT")
			exit(0);
		else if (command == "ADD")
		{
		}
	}
}