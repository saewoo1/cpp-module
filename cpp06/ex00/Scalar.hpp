#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>

class Scalar {
	public:
		static void convert(const std::string &literal);
		static double convertString(const std::string &literal);

		static void printChar(const std::string& str);
		static void printInt(const std::string& str);
		static void printFloat(const std::string& str);
		static void printDouble(const std::string& str);
	private:
		~Scalar();
		Scalar();
		Scalar& operator=(const Scalar &obj);
		Scalar(const Scalar &obj);
};

#endif