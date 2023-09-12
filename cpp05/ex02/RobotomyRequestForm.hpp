#ifdef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);

		RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);

		void executeAction(Bureaucrat const& obj) const;
};

#endif