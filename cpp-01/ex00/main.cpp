#include "Zombie.hpp"

/*
	stack -> 함수 호출 시, 지역 / 매개변수 저장 영역.
	호출이 완료되면 소멸.LIFO

	heap -> 사용자 직접 관리 메모리 영역, 사용자에 의해
	메모리 동적 할당, 해제
*/


int	main(void)
{
	Zombie	zombie1("Zombie 1(stack1) "); //생성자로 만듦 -> stack 영역
	Zombie	*zombie2 = newZombie("Zombie 2->(heap) "); // 직접 할당, heap 영역

	randomChump("Zombie3(just call func) "); // 함수 호출->생성자 호출 후 announce 호출, randomchump 종료 시 자동 소멸
	zombie1.announce(); // zombie class의 announce 호출
	zombie2->announce();
	delete	zombie2; // 직접 할당해줬으니 소멸자도 호출해야댐
	//함수 종료 전 생성자 호출로 생성된 zombie1 소멸자 호출
	return (0);
}