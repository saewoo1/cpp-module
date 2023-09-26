#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>

class Scalar {
	private:
		static void convertChar(double _double);
		static void convertInt(double _double);
		static void convertFloat(double _double);
		static void convertDouble(double _double);
		static void convertAscii(char c);
		Scalar();
		Scalar(const Scalar &obj);
		Scalar& operator=(const Scalar& obj);
		~Scalar();
	public:
		static void convertAll(const std::string& arg);
};

#endif