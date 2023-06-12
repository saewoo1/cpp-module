#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook pages;
	std::string command;
	int	i = 0;

	while (1)
	{
		std::cout << "Select Command! : EXIT / ADD / SEARCH : ";
		std::getline(std::cin, command);
		if (command.compare("EXIT") == 0)
			exit(0);
		else if (command.compare("ADD") == 0)
		{
			i %= 8;
			pages.AddPage(i);
			i++;
		}
		else if (command.compare("SEARCH") == 0)
			pages.PrintRes();
		else
			std::cout << "wrong command.. " << std::endl;
	}
}