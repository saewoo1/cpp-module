#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *array, size_t len, void(*func)(const T&)) {
    for (size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

template<typename T>
void printer(const T &t) {
    std::cout << t << std::endl;
}


# endif