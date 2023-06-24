#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed b( a );

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << std::endl;

  return 0;
}