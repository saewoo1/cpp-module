#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		this->inven[i] = 0;
	}
	// std::cout << "MateriaSource is created\n";
}

MateriaSource::MateriaSource(MateriaSource const &obj) {
	for (int i = 0; i < 4; i++) {
		if (obj.inven[i])
			this->inven[i] = obj.inven[i]->clone();
	}
	// std::cout << "Copy MateriaSource is called\n";
}

MateriaSource & MateriaSource::operator=(MateriaSource const & obj) {
	for (int i = 0; i < 4; i++) {
		if (this->inven[i])
			delete this->inven[i];
		if (obj.inven[i])
			this->inven[i] = obj.inven[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->inven[i])
			delete this->inven[i];
	}
	// std::cout << "MateriaSouce destructor is called\n";
}

void MateriaSource::learnMateria(AMateria *m) {
	int i = 0;
	while (this->inven[i] != 0 && i < 4)
		i++;
	if (i >= 4) {
		// std::cout << "Can't learn more 4 Materia\n";
		return ;
	}
	this->inven[i] = m;
	// std::cout << "Materia " << m->getType() << " learned\n";
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	int i = 0;
	while (this->inven[i] && this->inven[i]->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->inven[i])) {
		// std::cout << type << " materia is not exist\n";
		return NULL;
	}
	// std::cout << "Materia " << type << " created\n";
	return (this->inven[i]->clone());
}