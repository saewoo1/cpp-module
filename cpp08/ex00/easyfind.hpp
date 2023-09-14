#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <iostream>


//find는 찾으면 그 해당 지점의 첫번 째 idx를, 못찾으면 end를 반환한다.
// 기존의 find는 시작, 끝, val을 지정해줘야 하는데 이거 생략하고 container, value만 받아서 idx반환하도록.
// find -> begin은 포함되지만, end는 포함되지 않는다. easyfind에서는 이 부분을 exception으로 처리해보자.
template<typename T>
typename T::iterator easyfind(T& t, int n) {
    typename T::iterator iter;
    iter = std::find(t.begin(), t.end(), n);
    if (iter == t.end()) {
        throw std::runtime_error("can't find value in container");
    }
    return iter;
}

#endif