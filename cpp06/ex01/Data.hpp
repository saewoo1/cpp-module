#ifndef DATA_HPP
# define DATA_HPP

# include <cstdint>
# include <iostream>
# include <stdint.h>

class Data {
	public:
		std::string _str;
		Data();
		Data(const Data &obj);
		Data &operator=(const Data &obj);
		~Data();
};

#endif