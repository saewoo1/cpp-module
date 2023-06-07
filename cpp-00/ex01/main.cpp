#include "PhoneBook.hpp"

void	show_all_page(PhoneBook page[8])
{
	for (int i = 0; i < 8; i++)
		page[i].print_page();
}

void	show_all_info(PhoneBook page[8])
{
	std::cout << std::right << std::setw(10) << "idx";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Nick Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "PhoneNum";
	std::cout << "|";
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
		page[i].print_search(i);
}

void	idx_choice(PhoneBook page[8])
{
	int	i;
	std::string input_i;
	std::stringstream ss;

	std::cout << "page number? : ";
	std::getline(std::cin, input_i);
	ss << input_i;
	ss >> i;

	if (1 <= i && i <= 8 && !ss.fail())
		page[i - 1].print_page();
	else
		std::cout << "retry. wrong page number." << std::endl;
}

int	main()
{
	std::string str;
	PhoneBook page[8];
	int	i = 0;

	while (1)
	{
		std::cout << "Select command -> EXIT / ADD / SEARCH / ";
		std::getline(std::cin, str);
		if (str.compare("EXIT") == 0)
			exit(0);
		else if(str.compare("ADD") == 0)
		{
			i %= 8;
			page[i].add_page(i);
			i++;
		}
		else if(str.compare("SEARCH") == 0)
		{
			show_all_info(page);
			idx_choice(page);
		}
		else
			std::cout << "wrong command...." << std::endl;
	}
	
}