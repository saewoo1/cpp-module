#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    _unpairedDeq = -1;
    _unpairedVec = -1;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
        return *this;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
    *this = obj;
}

void PmergeMe::merge(int ac, char **av) {
    populateContainers(ac, av);
    printUnsortedSequence(ac);
    sortVec();
    sortDeq();
}

void PmergeMe::populateContainers(int ac, char **av) {
    std::set<int>   numbers;

    for (int i = 1; i < ac; i++) {
        int len = std::strlen(av[i]);
        for (int j = 0; j < len; j++) {
            if (!isdigit(av[i][j]) && av[i][j] != '+')
                throw std::invalid_argument("Error: Invalid argument.");
        }

        int num = std::atoi(av[i]);
        if (num < 0)
            throw std::runtime_error("Error: Negative Numbers are invalid");
        if (!numbers.insert(num).second)
            throw std::runtime_error("Error: Duplicated number are invalid");
        _inputVec.push_back(num);
        _inputDeq.push_back(num);
    }
}

template<typename T>
void PmergeMe::printSequence(const T &seq) {
    typename T::const_iterator iter;

    int i = 0;
    for (iter = seq.begin(); iter != seq.end(); ++iter) {
        std::cout << *iter << " ";
        if (i == 15) {
            std::cout << "[...]";
            break;
        }
        i++;
    }
    std::cout << std::endl;
}

void PmergeMe::printUnsortedSequence(int ac) {
    std::cout << "Before: ";
    for (int i = 0; i < (ac - 1); i++) {
        std::cout << _inputVec[i] << " ";
        if (i == 15) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    int pre1 = 0;
    int pre2 = 1;
    int cur = 0;

    for (int i = 2; i <= n; ++i) {
        cur = pre1 + 2 * pre2;
        pre1 = pre2;
        pre2 = cur;
    }
    return cur;
}

template<typename T>
void PmergeMe::jacobInsertSequence(T &tem, size_t len) {
    size_t  jacobIdx;
    int     i = 3;

    while ((jacobIdx = PmergeMe::jacobsthal(i)) < len - 1) {
        tem.push_back(jacobIdx);
        i++;
    }
}

void PmergeMe::posVec() {
    if (_pendingChainVec.empty())
        return ;
    PmergeMe::jacobInsertSequence(_jacobSeqVec, _pendingChainVec.size());
    size_t  last = 1;
    size_t  val = 1;

    for (size_t i = 0; i < _jacobSeqVec.size(); i++) {
        val = _jacobSeqVec.at(i);
        _posVec.push_back(val);

        size_t pos = val - 1;
        while (pos > last) {
            _posVec.push_back(pos);
            pos--;
        }
        last = val;
    }

    while (val++ < _pendingChainVec.size())
        _posVec.push_back(val);
}

void PmergeMe::insertVec() {
    std::vector<int>::iterator iter;
    size_t  count = 0;

    PmergeMe::posVec();
    for (iter = _posVec.begin(); iter < _posVec.end(); iter++) {
        int num = _pendingChainVec.at(*iter - 1);
        size_t endPos = *iter + count;
        size_t pos = PmergeMe::binarySearch(_mainChainVec, num, 0, endPos);
        _mainChainVec.insert(_mainChainVec.begin() + pos, num);
        count++;
    }
    if (_unpairedVec != -1) {
        size_t num = _unpairedVec;
        size_t pos = PmergeMe::binarySearch(_mainChainVec, num, 0, _mainChainVec.size() - 1);
        _mainChainVec.insert(_mainChainVec.begin() + pos, num);
    }
}

void PmergeMe::mergeSort(std::vector<int> &vec, int start, int end) {
    if (start >= end)
        return ;
    int mid = (start + end) / 2;

    mergeSort(vec, start, mid);
    mergeSort(vec, mid + 1, end);

    std::vector<int> sorted;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end) {
        if (vec[left] <= vec[right]) {
            sorted.push_back(vec[left]);
            left++;
        }
        else {
            sorted.push_back(vec[right]);
            right++;
        }
    }

    while (left <= mid) {
        sorted.push_back(vec[left]);
        left++;
    }
    while (right <= end) {
        sorted.push_back(vec[right]);
        right++;
    }
    for (int i = start; i <= end; i++)
        vec[i] = sorted[i - start];
}

void PmergeMe::sortVec() {
    clock_t start = clock();
    size_t size = _inputVec.size();

    if (size % 2 == 1) {
        _unpairedVec = _inputVec.back();
        _inputVec.pop_back();
    }

    for (size_t i = 0; i < size - 1; i += 2)
        _pairVec.push_back(std::make_pair(_inputVec[i], _inputVec[i + 1]));
    
    for (size_t i = 0; i < _pairVec.size(); i++ ) {
        if (_pairVec[i].first < _pairVec[i].second)
            std::swap(_pairVec[i].first, _pairVec[i].second);
        _mainChainVec.push_back(_pairVec[i].first);
        _pendingChainVec.push_back(_pairVec[i].second);
    }
    mergeSort(_mainChainVec, 0, _mainChainVec.size() - 1);
    _mainChainVec.insert(_mainChainVec.begin(), _pendingChainVec[0]);
    insertVec();
    displaySortInfo(start, _mainChainVec);
}

void PmergeMe::posDeque() {
    if (_pendingChainDeq.empty())
        return ;
    jacobInsertSequence(_jacobSeqDeq, _pendingChainDeq.size());
    size_t  last = 1;
    size_t  val = 1;

    for (size_t i = 0; i < _jacobSeqDeq.size(); i++) {
        val = _jacobSeqDeq.at(i);
        _posDeq.push_back(val);

        size_t pos = val - 1;
        while (pos > last) {
            _posDeq.push_back(pos);
            pos--;
        }
        last = val;
    }

    while (val++ < _pendingChainDeq.size())
        _posDeq.push_back(val);
}

void PmergeMe::insertDeque() {
    std::deque<int>::iterator it;
	size_t addCount = 0;

	posDeque();
	for (it = _posDeq.begin(); it < _posDeq.end(); it++)
	{
		int n = _pendingChainDeq.at(*it - 1);

		size_t endPos = *it + addCount;
		size_t pos = binarySearch(_mainChainDeq, n, 0, endPos);
		_mainChainDeq.insert(_mainChainDeq.begin() + pos, n);
		addCount++;
	}
	if (_unpairedDeq != -1)
	{
		size_t nbr = _unpairedDeq;
		size_t pos = binarySearch(_mainChainDeq, nbr, 0, _mainChainDeq.size() - 1);
		_mainChainDeq.insert(_mainChainDeq.begin() + pos, nbr);
	}
}

void PmergeMe::mergeSort(std::deque<int> &deq, int start, int end) {
    if (start >= end)
        return ;
    
    int mid = (start + end) / 2;

    mergeSort(deq, start, mid);
    mergeSort(deq, mid + 1, end);

    std::deque<int> sorted;


    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end) {
        if (deq[left] <= deq[right]) {
            sorted.push_back(deq[left]);
            left++;
        }
        else {
            sorted.push_back(deq[right]);
            right++;
        }
    }

    while (left <= mid) {
        sorted.push_back(deq[left]);
        left++;
    }
    while (right <= end) {
        sorted.push_back(deq[right]);
        right++;
    }
    for (int i = start; i <= end; i++)
        deq[i] = sorted[i - start];
}

void PmergeMe::sortDeq() {
    clock_t start = clock();
    size_t size = _inputDeq.size();

    if (size % 2 == 1) {
        _unpairedDeq = _inputDeq.back();
        _inputDeq.pop_back();
    }

    for (size_t i = 0; i < size - 1; i += 2)
        _pairDeq.push_back(std::make_pair(_inputDeq[i], _inputDeq[i + 1]));

    for (size_t i = 0; i < _pairDeq.size(); i++ ) {
        if (_pairDeq[i].first < _pairDeq[i].second)
            std::swap(_pairDeq[i].first, _pairDeq[i].second);
        _mainChainDeq.push_back(_pairDeq[i].first);
        _pendingChainDeq.push_back(_pairDeq[i].second);
    }
    mergeSort(_mainChainDeq, 0, _mainChainDeq.size() - 1);
    _mainChainDeq.insert(_mainChainDeq.begin(), _pendingChainDeq[0]);
    insertDeque();
    displaySortInfo(start, _mainChainDeq);
}

template<typename T>
void PmergeMe::displaySortInfo(clock_t start, const T &mainSeq) {
    clock_t end = clock();
    double timePassMs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "After:  ";
    printSequence(mainSeq);
    std::cout << "Time to process a range of "<< mainSeq.size();
    std::cout << " elements with " << (typeid(mainSeq) == typeid(std::vector<int>) ? "std::vector" : "std::deque");
    std::cout << " : " << timePassMs << " ms" << std::endl;
}

template<typename T>
int PmergeMe::binarySearch(T &container, int n, int begin, int end) {
    int mid;

    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (n == container.at(mid))
            return (mid);
        if (n > container.at(mid))
            begin = mid + 1;
        else
            end = mid - 1;
    }
    if (n > container.at(mid))
        return (mid + 1);
    else
        return (mid);
}