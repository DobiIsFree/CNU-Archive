#include <iostream>

template<typename T>
void swapXX(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
template<>
void swapXX(std::string& a, std::string& b) {
	// 인자를 받을 때 명시적으로 받아 : teemplate specialization
	// 다른 동작을 일어나게 할 수 있다
	// 실행 결과 원래대로라면 e, f가 바뀐 e:hello, f:world -> 아무 동작 수행하지 않는 것 확인
}

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "world";
	std::string f = "hello";

	swapXX<int>(a, b);
	swapXX<float>(c, d);
	swapXX < std::string>(e, f);

	std::cout << "a:" << a << ",b:" << b << std::endl;
	std::cout << "c:" << c << ",d:" << d << std::endl;
	std::cout << "e:" << e << ",f:" << f << std::endl;

	return 0;
}
