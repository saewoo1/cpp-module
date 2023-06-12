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
		Fixed(int num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		~Fixed(void);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
		int	toInt(void) const;
		float toFloat(void) const;

		Fixed& operator=(const Fixed& obj);
		
		bool operator<(const Fixed& obj) const;
		bool operator>(const Fixed& obj) const;
		bool operator>=(const Fixed& obj) const;
		bool operator<=(const Fixed& obj) const;
		bool operator==(const Fixed& obj) const;
		bool operator!=(const Fixed& obj) const;

		Fixed operator+(const Fixed& obj) const;
		Fixed operator-(const Fixed& obj) const;
		Fixed operator*(const Fixed& obj) const;
		Fixed operator/(const Fixed& obj) const;

		Fixed &operator++(void);
		const Fixed operator++(int);
		Fixed &operator--(void);
		const Fixed operator--(int);

		static Fixed &min(Fixed &obj1, Fixed &obj2);
		static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
		static Fixed &max(Fixed &obj1, Fixed &obj2);
		static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
};
		std::ostream& operator<<(std::ostream &out, const Fixed &obj);
#endif