#include <iostream>
#include <string>
#include <cassert>

class Base {
	std::string s;

public:
	Base() : s("Base") { std::cout << "Base class constructor" << std::endl; }

	virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	std::string s;

public:
	Derived() : s("Derived"), Base() { std::cout << "Derived class constructor" << std::endl; }

	void what() { std::cout << s << std::endl; }
};
int main() {

	Base p;
	Derived c;

	std::cout << " === Pointer ===" << std::endl;
	Base* xx = &c;//OK.upcast
	// Derived* yy = dynamic_cast<Derived*>(xx);
	// 런타임 에러 : 널 포인터 반환, 포인터를 다룰 때 타입이 호환되지 않으면 NULL pointer 반환
	Derived* yy = dynamic_cast<Derived*>(&p); // Base object를 Derived class로 다운 캐스팅 시도
	yy->what();

	//getchar();
	return 0;
}