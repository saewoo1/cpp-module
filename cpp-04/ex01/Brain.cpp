#include "Brain.hpp"
#include <iostream>


Brain::Brain(void) {
	this->ideas = new std::string[100];

	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "Brain is filling....";
	}
	std::cout << "Brain Class Constructor is called and Ideas are filled!!!!\n";
}
Brain::~Brain(void) {
	delete[] (this->ideas);
	std::cout << "Brain Class Destructor is called, Ideas are gone..\n";
}
Brain& Brain::operator=(const Brain &obj) {
	std::cout << "Copy assignment\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return (*this);
}
Brain::Brain(const Brain &obj) {
	std::string *tmp = obj.getIdeas();
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = tmp[i] + " but this is stolen";
	}
	std::cout << "Brain Copy Constructor is called clone Brain\n";
}
std::string *Brain::getIdeas(void) const {
	return (this->ideas);
}

void Brain::setIdeas(std::string contents, int i) {
	this->ideas[i] = contents;
}
std::string Brain::getOneIdea(int i) {
	return (this->ideas[i]);
}

