#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed b( a );
  Fixed c;

  c = b; // 복사생성자는 '생성' 시에 호출이 된다. 이는 연산자 오버로딩 호출.
  //Fixed c = b; 얘는 복사생성자 호출임

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << "------------before change" << std::endl;
  std::cout << c.getRawBits() << std::endl;
  c.setRawBits(42);
  std::cout << "------------c val is 42" << std::endl;
  std::cout << a.getRawBits() << std::endl;
  std::cout << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << std::endl;
  std::cout << c.getRawBits() << std::endl;
  std::cout << std::endl;


  return 0;
}