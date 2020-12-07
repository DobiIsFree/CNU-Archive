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
	// 런타임 에러 : 참조를 다룰 때 호환되지 않아, 예외를 던지게 된다.
	Derived yy = dynamic_cast<Derived&>(p); // 잘못된 레퍼런스 캐스팅 base를 derived로 다운캐스팅 시도
	yy.what();

	//getchar();
	return 0;
}
