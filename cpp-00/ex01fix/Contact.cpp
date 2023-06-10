#include "Contact.hpp"

void Contact::SetFirstName(std::string s)
{
	this->first_name = s;
}
void Contact::SetLastName(std::string s)
{
	this->last_name = s;
}
void Contact::SetNickName(std::string s)
{
	this->nick_name = s;
}
void Contact::SetPhoneNumber(std::string s)
{
	this->phone_number = s;
}
void Contact::SetSecret(std::string s)
{
	this->darkest_secret = s;
}

std::string Contact::GetFirstName(void) const
{
	return (this->first_name);
}
std::string Contact::GetLastName(void) const
{
	return (this->last_name);
}
std::string Contact::GetNickName(void) const
{
	return (this->nick_name);
}
std::string Contact::GetPhoneNumber(void) const
{
	return (this->phone_number);
}
std::string Contact::GetSecret(void) const
{
	return (this->darkest_secret);
}