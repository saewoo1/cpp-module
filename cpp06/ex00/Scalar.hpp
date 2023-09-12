#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>

class Scalar {
	public:
		~Scalar();
		Scalar();
		Scalar& operator=(const Scalar &obj);
		static void ScalarConverter(const std::string& literal);

};

#endif