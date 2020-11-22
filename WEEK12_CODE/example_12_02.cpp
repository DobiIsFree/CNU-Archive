#include <iostream>

template<typename T>
T min(T x, T y) {		// 더 작은 값 반환
	return x < y ? x : y;
}
int main() {
	int x = 3;
	int y = 2;
	double d = 2.1;
	double e = 3.3;
	std::cout << "min(x,y) : " << min(x, y) << ", min(d,e) : " << min(d, e) << ", min(d,x) : " << min<double>(d, x) << std::endl;
	//   (int , int) 	(double, double)  (double, int)
	// <double>을 사용해 명시적으로 알리면 올바른 값 출력하는 것 확인
	// 형을 섞어 호출할 경우, 적절한 type 찾지 못해, 명시적으로 형을 지정해주면 오류 해결^^
	return 0;
}
