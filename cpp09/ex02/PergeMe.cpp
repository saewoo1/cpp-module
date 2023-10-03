#include "PergeMe.hpp"

bool isDigit(char *str) {
	int	i = 0;
	while (str[i] && str[i] >= '0' && str[i] < '9')
		i++;
	if (!str[i])
		return true;
	return false;
}

int vectorSort(std::vector<int> &vector, int ac, char **av)
{
	std::clock_t	start = clock();
	if (fillVector(vector, ac, av))
		return (2);

	std::cout << "Before vector sort : " << std::endl;
	printVector(vector);

	divideVector(vector, 0, vector.size() - 1);
	std::cout << "After vector sort : ";
	printVector(vector);

	double time = 1000000.0 * (clock() - start) / CLOCKS_PER_SEC;
	std::cout << "[" << time << "]" << " ms to sort with std::vector" << std::endl;
	return 0;
}


int	fillVector(std::vector<int> &vector, int ac, char **av) {
	int	number;

	for (int i = 1; i < ac; i++) {
		std::istringstream iss(av[i]);

		if (isDigit(av[i]) && iss >> number && number >= 0)
			vector.push_back(number);
		else {
			std::cout << av[i] << " : is not a positive integer " << std::endl;
			return 1;
		}
	}
	return (0);
}

void printVector(const std::vector<int> vector) {
	for (std::vector<int>::const_iterator iterator = vector.begin(); iterator != vector.end(); iterator++) {
		std::cout << *iterator << " ";
	}
	std::cout << std::endl;
}

void divideVector(std::vector<int> &vector, int left, int right) {
	if (left < right) {
		int	mid = (left + right) / 2;
		divideVector(vector, left, mid);
		divideVector(vector, mid + 1, right);
		mergeVector(vector, left, mid, right);
	}
}

void mergeVector(std::vector<int> &vector, int left, int mid, int right) {
	int leftVectorSize = mid - left + 1;
	int rightVectorSize = right - mid;

	std::vector<int>	leftSide(leftVectorSize);
	std::vector<int>	rightSide(rightVectorSize);

	for (int i = 0; i < leftVectorSize; i++)
		leftSide[i] = vector[left + 1];
	for (int i = 0; i < rightVectorSize; i++)
		rightSide[i] = vector[mid + i + 1];

	int i = 0, j = 0, k = left;
	while (i < leftVectorSize && j < rightVectorSize) {
		if (leftSide[i] < rightSide[i]) {
			vector[k] = leftSide[i];
			i++;
		}
		else {
			vector[k] = rightSide[j];
			j++;
		}
		k++;
	}

	while (i < leftVectorSize) {
		vector[k] = leftSide[i];
		k++;
		i++;
	}
	while(j < rightVectorSize) {
		vector[k] = rightSide[j];
		k++;
		j++;
	}
}

int	listSort(std::list<int> &list, int ac, char **av) {
	std::clock_t	start = clock();
	fillList(list, ac, av);
	std::cout << "Before sort list : ";
	printList(list);

	divideList(list, list.begin(), list.end());
	std::cout << "After list sort : ";
	printList(list);

	double time = 1000000.0 * (clock() - start) / CLOCKS_PER_SEC;
	std::cout << "[" << time << "]" << "ms to sort with std::list" << std::endl;
}


int fillList(std::list<int> &list, int ac, char **av) {
	int	number;

	for (int i = 1; i < ac; i++) {
		std::istringstream iss(av[i]);
		iss >> number;
		list.push_back(number);
	}
}

void printList(const std::list<int> list) {
	for (std::list<int>::const_iterator iter = list.begin(); iter != list.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

void divideList(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right) {
	if (std::distance(left, right) > 1) {
		std::list<int>::iterator mid = left;
		std::advance(mid, std::distance(left, right) / 2);

		divideList(list, left, mid);
		divideList(list, mid, right);
		mergeList(left, mid, right);
	}
}

void mergeList(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right) {
	std::list<int> mergedList;

	std::list<int>::iterator leftList = left;
	std::list<int>::iterator rightList = right;

	while (leftList != mid && rightList != right) {
		if (*leftList < *rightList) {
			mergedList.push_back(*leftList);
			++leftList;
		}
		else {
			mergedList.push_back(*rightList);
			++rightList;
		}
	}

	while (leftList != mid) {
		mergedList.push_back(*leftList);
		++leftList;
	}
	while (rightList != right) {
		mergedList.push_back(*rightList);
		++rightList;
	}

	for (std::list<int>::iterator itor = left, mergedIt = mergedList.begin(); itor != right; ++itor, ++mergedIt) {
		*itor = *mergedIt;
	}
}