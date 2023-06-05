#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>


class PhoneBook {
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void	add_page(int i);
		void	print_page(void);
		void	set_length(std::string info);
		void	print_search(int i);
		bool	valid_phone_number(std::string s);
};

#endif