#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void SetFirstName(std::string s);
		void SetLastName(std::string s);
		void SetNickName(std::string s);
		void SetSecret(std::string s);
		void SetPhoneNumber(std::string s);
		std::string GetFirstName(void) const;
		std::string GetLastName(void) const;
		std::string GetNickName(void) const;
		std::string GetPhoneNumber(void) const;
		std::string GetSecret(void) const;
};

#endif