#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int	val;
		int static const bit = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif