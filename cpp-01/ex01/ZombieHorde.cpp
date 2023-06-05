#include "Zombie.hpp"
Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	std::stringstream	ss;

	for (int i = 0; i < N; i++)
	{
		ss.str(std::string());
		ss << i + 1;
		horde[i].set_name(name + ss.str() + " ");
	}
	return (horde);
}