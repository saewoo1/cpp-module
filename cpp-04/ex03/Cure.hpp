#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria{
	private:
		std::string type;
	public:
		Cure();
		~Cure();
		Cure(Cure const &obj);
		Cure & operator=(Cure const & obj);
		std::string const & getType() const;

		Cure * clone() const;
		void use(ICharacter& target);
};

#endif