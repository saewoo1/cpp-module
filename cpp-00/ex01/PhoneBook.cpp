#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

bool	PhoneBook::IsValidStr(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isalpha(s[i]))
			return (false);
	}
	return (true);
}

bool	PhoneBook::IsValidNum(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}

void	PhoneBook::AddPage(int i)
{
	std::string tmp;

	std::cout << "First name : ";
	std::getline(std::cin, tmp);
	while (!tmp.length() || !IsValidStr(tmp))
	{
		std::cout << "wrong info, try again.." << std::endl;
		std::cout << "First name : ";
		std::getline(std::cin, tmp);
	}
	this->contacts[i].SetFirstName(tmp);

	std::cout << "Last name : ";
	std::getline(std::cin, tmp);
	while (!tmp.length() || !IsValidStr(tmp))
	{
		std::cout << "wrong info, try again.." << std::endl;
		std::cout << "Last name : ";
		std::getline(std::cin, tmp);
	}
	this->contacts[i].SetLastName(tmp);

	std::cout << "Nick name : ";
	std::getline(std::cin, tmp);
	while (!tmp.length())
	{
		std::cout << "wrong info, try again.." << std::endl;
		std::cout << "Nick name : ";
		std::getline(std::cin, tmp);
	}
	this->contacts[i].SetNickName(tmp);

	std::cout << "Phone number : ";
	std::getline(std::cin, tmp);
	while (!tmp.length() || !IsValidNum(tmp))
	{
		std::cout << "wrong info, try again.." << std::endl;
		std::cout << "Phone number : ";
		std::getline(std::cin, tmp);
	}
	this->contacts[i].SetPhoneNumber(tmp);

	std::cout << "Darkest secret : ";
	std::getline(std::cin, tmp);
	while (!tmp.length())
	{
		std::cout << "wrong info, try again.." << std::endl;
		std::cout << "Darkest secret : ";
		std::getline(std::cin, tmp);
	}
	this->contacts[i].SetSecret(tmp);
	std::cout << "Save clear!" << std::endl;
}

void	PhoneBook::PrintPage(Contact page)
{
	std::cout << "First name : " << page.GetFirstName() << std::endl;
	std::cout << "Last name : " << page.GetLastName() << std::endl;
	std::cout << "Nick name : " << page.GetNickName() << std::endl;
	std::cout << "Phone number : " << page.GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << page.GetSecret() << std::endl;
}

void	PhoneBook::SetLength(std::string info)
{
	if (info.length() <= 10)
		std::cout << std::right << std::setw(10) << info;
	else
	{
		info = info.substr(0,9) + ".";
		std::cout << std::right << std::setw(10) << info;
	}
}

void	PhoneBook::PrintSearch(Contact page, int i)
{
	std::stringstream ss;
	ss << i + 1;
	SetLength(ss.str());
	std::cout << "|";
	SetLength(page.GetFirstName());
	std::cout << "|";
	SetLength(page.GetLastName());
	std::cout << "|";
	SetLength(page.GetNickName());
	std::cout << std::endl;
}

void	PhoneBook::PrintRes()
{
	std::string input_i;
	int	i = 0;

	std::cout << std::right << std::setw(10) << "idx";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "First name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Last name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
		if (this->contacts[i].GetFirstName().empty() == false)
			PrintSearch(this->contacts[i], i);
	
	while (true)
	{
		std::cout << "Page number? : ";
		std::getline(std::cin, input_i);
		std::stringstream ss(input_i);
		ss >> i;
		if ((i >= 1 && i <= 8) && this->contacts[i - 1].GetFirstName().empty() == false)
			break ;
		std::cout << "Wrong index, try again..." << std::endl;
	}
	PrintPage(this->contacts[i - 1]);
}