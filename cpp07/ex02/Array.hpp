#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {
    private:
        unsigned int len;
        T *array;

    public:
        Array() : len(0), array(new T()) {};
        Array(unsigned int n) : len(n), array(new T[n]) {};
        ~Array() {
            delete[] array;
        };
        Array(const Array &obj) : len(obj.size()), array(new T[obj.size()]) {
            for (unsigned int i = 0; i < len; i++) {
                array[i] = obj.array[i];
            }
        };
        Array& operator=(const Array &obj) {
            if (this != &obj) {
                delete[] array;
                array = new T[obj.size()];
                len = obj.len;
                for (unsigned int i = 0; i < len; i++) {
                    array[i] = obj.array[i];
                }
            }
            return *this;
        };

        T& operator[](unsigned int i) const {
            if (i >= len) {
                throw OutofBoundery();
            }
            return array[i];
        }

        unsigned int size(void) const {
            return len;
        }

        class OutofBoundery : public std::exception {
            public:
                const char* what() const throw() {return "index is out...";}
        };
};
template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T>&arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        out << arr[i] << " ";
    }
    return out;
}

#endif