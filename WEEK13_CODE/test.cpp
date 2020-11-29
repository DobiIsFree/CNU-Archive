#include <iostream>

struct Functor
{
	void operator()() {
		std::cout << "functor executed" << std::endl;
	}
};
struct FunctorWithX
{
	void operator()(int x) {
		std::cout << "functor with arg executed : " << x << std::endl;
	}
};

int main(){
    Functor functor;
    functor();

    FunctorWithX functorX;
    functorX(10);
}
