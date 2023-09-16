#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFROM_HPP


# include "AForm.hpp"
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);

		RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);

		void execute(const Bureaucrat &bureaucrat) const;
};

#endif