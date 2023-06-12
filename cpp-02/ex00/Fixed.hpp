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
		Fixed(const Fixed& obj); // 얕은복사
		Fixed& operator=(const Fixed& obj); // 객체도 기본 자자료료형처럼 연연산  가가능능
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif