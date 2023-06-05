#include "PhoneBook.hpp"

bool	PhoneBook::valid_phone_number(std::string s)
{
	for (int i = 0; i < s.length(); i++)
	if(!isdigit(s[i]))
		return (false);
	return (true);
}

void	PhoneBook::add_page(int i) // 정보 받기
{
	i = i;

	std::cout << "First name : ";
	std::getline(std::cin, first_name);
	std::cout << "last name : ";
	std::getline(std::cin, last_name);
	std::cout << "nick name : ";
	std::getline(std::cin, nick_name);
	std::cout << "phone num : ";
	std::getline(std::cin, phone_number);
	std::cout << "darkest secret : ";
	std::getline(std::cin, darkest_secret);
	if (!valid_phone_number(phone_number))
	{
		std::cout << "you input wrong info, try again.." << std::endl;
		add_page(i);
	}
}

void	PhoneBook::print_page(void) // 해당 정보 프린트
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
	set_length(std::to_string(i));
	std::cout << "|";
	set_length(first_name);
	std::cout << "|";
	set_length(last_name);
	std::cout << "|";
	set_length(nick_name);
	std::cout << "|";
	set_length(phone_number);
	std::cout << "|";
	set_length(darkest_secret);
	std::cout<< "|";
	std::cout << std::endl;
}