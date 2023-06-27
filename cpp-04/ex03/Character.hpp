#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria* inven[4];
	public:
		Character();
		Character(std::string name);
		Character(Character const & obj);
		~Character();
		Character &operator=(Character const &obj);

		std::string const & getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* getMateriaFromInventory(int idx);
};