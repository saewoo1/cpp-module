#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	private:
		std::string *ideas;
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &obj);
		Brain& operator=(const Brain &obj);

		std::string *getIdeas(void) const;
};

#endif