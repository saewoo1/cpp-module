#include "PhoneBook.hpp"

bool	PhoneBook::valid_phone_number(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if(!isdigit(s[i]))
		{
			std::cout << "unvalid number" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	PhoneBook::valid_alpha(std::string s)
{
	if (!s.length())
	{
		std::cout << "unvalid info" << std::endl;
		return (false);
	}
	for (size_t i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]) != 1 && isalpha(s[i]) != 2)
		{
			std::cout << "unvalid info" << std::endl;
			return (false);
		}
	}
		return (true);
}

void	PhoneBook::add_page(int i)
{
	i = 0;
	std::cout << "First name : ";
	std::getline(std::cin, first_name);
	while (!first_name.length() || !valid_alpha(first_name))
	{
		std::cout << "First name : ";
		std::getline(std::cin, first_name);
	}
	std::cout << "last name : ";
	std::getline(std::cin, last_name);
	while (!last_name.length() || !valid_alpha(last_name))
	{
		std::cout << "last name : ";
		std::getline(std::cin, last_name);
	}
	std::cout << "nick name : ";
	std::getline(std::cin, nick_name);
	while (!nick_name.length())
	{
		std::cout << "First name : ";
		std::getline(std::cin, nick_name);
	}
	std::cout << "Phone num : ";
	std::getline(std::cin, phone_number);
	while (!phone_number.length() || !valid_phone_number(phone_number))
	{
		std::cout << "Phone num : ";
		std::getline(std::cin, phone_number);
	}
	std::cout << "darkest secret : ";
	std::getline(std::cin, darkest_secret);
	while (!darkest_secret.length())
	{
		std::cout << "First name : ";
		std::getline(std::cin, darkest_secret);
	}
}

void	PhoneBook::print_page(void)
{
	std::cout << "First name : " << first_name << std::endl;
	std::cout << "last name : " << last_name << std::endl;
	std::cout << "nick name : " << nick_name << std::endl;
	std::cout << "phone num : " << phone_number << std::endl;
	std::cout << "darkest secret : " << darkest_secret << std::endl;
}

void	PhoneBook::set_length(std::string info)
{
	if (info.length() <= 10)
		std::cout << std::right << std::setw(10) << info;
	else
	{
		info = info.substr(0,9) + ".";
		std::cout << std::right << std::setw(10) << info;
	}
}

void	PhoneBook::print_search(int i)
{
	std::stringstream ss;

	ss << i + 1;
	set_length(ss.str());
	std::cout << "|";
	set_length(first_name);
	std::cout << "|";
	set_length(last_name);
	std::cout << "|";
	set_length(nick_name);
	std::cout << "|";
	set_length(phone_number);
	std::cout << "|";
	std::cout << std::endl;
}