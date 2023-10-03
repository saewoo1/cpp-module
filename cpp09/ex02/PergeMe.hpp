#ifndef PERGEME_HPP
# define PERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>

bool isDigit(char *str);

//vertor
int	vectorSort(std::vector<int> &vector, int ac, char **av);
int fillVector(std::vector<int> &vector, int ac, char **av);
void	printVector(const std::vector<int> vector);
void	divideVector(std::vector<int> &vector, int left, int right);
void	mergeVector(std::vector<int> &vector, int left, int mid, int right);

//list
int	ListSort(std::list<int> &list, int ac, char **av);
int fillList(std::list<int> &list, int ac, char **av);
void	printList(const std::list<int> list);
void	divideList(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right);
void	mergeList(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right);


#endif