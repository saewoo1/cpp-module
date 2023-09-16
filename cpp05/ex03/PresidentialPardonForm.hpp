#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string& getTarget);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);

		void execute(const Bureaucrat &obj) const;
};

# endif