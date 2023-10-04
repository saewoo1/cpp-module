#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <deque>
# include <set>

class PmergeMe {
    private:
        int _unpairedVec;
        int _unpairedDeq;

        std::vector<int>    _inputVec;
        std::vector<int>    _mainChainVec;
        std::vector<int>    _pendingChainVec;
        std::vector<int>    _jacobSeqVec;
        std::vector<int>    _posVec;
        std::vector<std::pair<int, int> >    _pairVec;

        std::deque<int>     _inputDeq;
        std::deque<int>     _mainChainDeq;
        std::deque<int>     _pendingChainDeq;
        std::deque<int>     _jacobSeqDeq;
        std::deque<int>     _posDeq;
        std::deque<std::pair<int, int> >     _pairDeq;

        void    populateContainers(int ac, char **av);
        void    printUnsortedSequence(int ac);
        int     jacobsthal(int n);

        void    sortVec();
        void    mergeSort(std::vector<int> &vec, int start, int end);
        void    insertVec();
        void    posVec();

        void    sortDeq();
        void    mergeSort(std::deque<int> &deq, int start, int end);
        void    insertDeque(void);
        void    posDeque();
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &obj);

        void    merge(int ac, char **av);

        template<typename T>
        void    printSequence(const T &tem);

        template<typename T>
        void displaySortInfo(clock_t, const T &tem);

        template<typename T>
        void jacobInsertSequence(T &tem, size_t len);

        template<typename T>
        int binarySearch(T &deq, int n, int begin, int end);

};

#endif