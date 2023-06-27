#include "Character.hpp"

Character::Character() {
	this->name = "default";
	// std::cout << "default Character is created" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inven[i] = 0;
	}
}

Character::Character(std::string name) : name(name) {
	// std::cout << this->name << " Character is created" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inven[i] = 0;
	}
}

Character::Character(Character const & obj) : name(obj.getName() + "_copy") {
	for (int i = 0; i < 4; i++) {
		if (obj.inven[i])
			this->inven[i] = obj.inven[i]->clone();
	}
	// std::cout << this->name << " Character is created by " << obj.getName() << std::endl;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->inven[i])
			delete this->inven[i];
	}
	// std::cout << "Character destructor is called and inven are destroyed" << std::endl;
}

Character & Character::operator=(Character const & obj) {
	for (int i = 0; i < 4; i++) {
		if (this->inven[i])
			delete this->inven[i];
		if (obj.inven[i])
			this->inven[i] = obj.inven[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	int	i = 0;

	if (!m) {
		// std::cout << this->name << " can't equip because it has nothing" << std::endl;
		return ;
	}
	while (this->inven[i] != 0 && i < 4)
		i++;
	if (i >= 4) {
		// std::cout << this->name << " can't equip more than 4 Materia" << std::endl;
		return ;
	}
	this->inven[i] = m;
	// std::cout << this->name << " equip materia " << m->getType() << " in inven num " << i << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		// std::cout << this->name << " over idx..? bye\n";
		return ;
	}
	else if (!(this->inven[idx])){
		// std::cout << this->name << " has nothing in inven.. can't unequip\n";
		return ;
	}
	else {
		AMateria *tmp = this->inven[idx];
		// std::cout << this->name << " unequipped " << tmp->getType() << " at inven num " << idx << std::endl;
		this->inven[idx] = 0; 
	}
}

void Character::use(int idx, ICharacter& target) {
	std::string str = this->getName();
	if (idx < 0 || idx >= 4 || !this->inven[idx]) {
		// std::cout << "Inven Can't find anything number " << idx << std::endl;
		return ;  
	}
	this->inven[idx]->use(target);
}


AMateria *Character::getMateriaFromInventory(int idx) {
	return (this->inven[idx]);
}