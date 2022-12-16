#include <iostream>
/* count 값 변화 추이의 이유 */
template <typename T>
void func(const T& x) {
	static int count = 0;
	std::cout << "x = " << x << ", count = " << count << std::endl;
	++count;
}

int main() {
	func<int>(1);
	std::cout << std::endl;

	func<int>(1);
	std::cout << std::endl;
	
	func<double>(1.1);
	std::cout << std::endl;
	
	func<int>(1);
	return 0;
/*	
	x = 1, count = 0
	x = 1, count = 1
	x = 1.1, count = 0
	x = 1, count = 2
*/
}
/* 타입 인자마다 다른 코드 생성해, Int형과 double이 따로 존재 */