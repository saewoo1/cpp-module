#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	val; // 고정소수점 값
		int static const bit = 8; // 소수의 비트 수 저장
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		int	getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed(int num);
		Fixed(const float num);
		int	toInt(void) const;
		float toFloat(void) const;
};
		std::ostream& operator<<(std::ostream &out, const Fixed &obj);
#endif