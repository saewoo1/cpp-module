#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>

class Scalar {
	public:
		static void ScalarConverter(const std::string& literal);
	private:
		~Scalar();
		Scalar();
		Scalar& operator=(const Scalar &obj);
		Scalar(const Scalar &obj);
};

#endif