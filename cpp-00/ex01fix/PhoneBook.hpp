#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		i;
	public:
		void AddPage(Contact page);
		void PrintPage(Contact page);
		void SetLength(std::string info);
		void PrintSearch(Contact page, int i);
		bool IsValidStr(std::string s);
		bool IsValidNum(std::string s);
		void PrintRes(void);
};