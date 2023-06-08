#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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

		Fixed(int num);
		Fixed(const float num);
		int	toInt(void);
};
#endif