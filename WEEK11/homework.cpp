#include <iostream>
#include <string.h>
using namespace std;
/*
Animal - int weight, string name, 
	   - void eat()  // weight increase      "[" + name + "] ***를 먹고 있습니다. (현재 몸무게: " + weight + ")" 
	   - void action(int x) //weight decrease     "[" + name + "] *** 하고 있습니다. (현재 몸무게: " + weight + ")"
Dog    - int happniess, 
       - void getHappniess(out),  "[" + name + "] 의 행복도는 [" + happiness + "] 입니다."
       - void upHappniess()        toy: +30 poodle: +50 standard : +40
       (action() ->  happniess += x)
Bird   - int altitude, 
       - int getAltitude(), 
       - Bird& operator>
       (action() ->  altitude += x)

Dog -> Toy, Poodle, Standard
Bird -> Vulture, Swallow, Chicken
*/
/* Task 1 */
// Animal
class Animal{
public:
	Animal(int weight, string name) : weight(weight), name(name){}
	int weight;
	string name;
	virtual void eat() = 0;
	virtual void action(int x) = 0;
};
/* Task 2 */
// Bird
class Bird : public Animal{
public:
	int altitude;
	Bird(int weight, string name, int altitude) :  Animal(weight, name), altitude(altitude) {}
	void eat() override {
		weight += 20;
        cout<<"[" << name << "] 지렁이를 먹고 있습니다. (현재 몸무게: " << weight << ")" <<endl;
	}
    void action(int x) override {
        altitude += x;
        weight -= 10;
        cout<< "[" << name << "] 하늘을 날고 있습니다. (현재 몸무게: " << weight << ", 현재 고도: "<< altitude << ")"<<endl;
    }
    virtual int getAltitude() = 0;
    virtual Bird& operator>(Bird &anoter) =0;
};
/* Task 3 */
// Dog
class Dog : public Animal{
    public:
		int happiness;
        
        Dog(int weight, string name, int happiness) : Animal(weight, name) , happiness(happiness){}
        
        void eat() override{
			weight ++;
            cout<<"[" << name << "] 사료를 먹고 있습니다. (현재 몸무게: " << weight << ")" <<endl;
		}
        
        void action(int x) override{
			weight--;
			happiness += x * 10;
            cout<<"[" << name << "] 산책을 하고 있습니다. (현재 몸무게: " << weight << ")" <<endl;
		}

        virtual void getHappniess() =0;
        virtual void upHappiness() =0;
};
/* Task 4, 5, 6, 7 ... */
// Vulture -> Toy -> Swallow -> Poodle -> Chicken -> Standard
class Vulture : public Bird {
public :
    Vulture(int weight, string name, int altitude) : Bird(weight, name, altitude) {}
    
    int getAltitude() override{
		return this->altitude;
	}

    Bird& operator>(Bird& another)override {
        return (this->altitude > another.getAltitude() ? *this : another);
	}
};
class Toy : public Dog {
public: 
    Toy(int weight, string name, int happniess) : Dog(weight, name, happniess) {}

    void getHappniess() override {
        cout<<"[" << name << "] 의 행복도는 [" << happiness << "] 입니다."<<endl;
    }
    void upHappiness() override {
        happiness += 30;
    }
};
class Swallow : public Bird{
public:
    Swallow(int weight, string name, int altitude) : Bird(weight, name, altitude) {}
    
    int getAltitude() override{
		return this->altitude;
	}

    Bird& operator>(Bird& another)override {
        return (this->altitude > another.getAltitude() ? *this : another);
	}
};
class Poodle : public Dog{
public: 
    Poodle(int weight, string name, int happniess) : Dog(weight, name, happniess) {}

    void getHappniess() override {
        cout<<"[" << name << "] 의 행복도는 [" << happiness << "] 입니다."<<endl;
    }
    void upHappiness() override {
        happiness += 50;
    }
};
class Chicken :public Bird{
public:
     Chicken(int weight, string name, int altitude) : Bird(weight, name, altitude) {}
    
    int getAltitude() override{
		return this->altitude;
	}

    Bird& operator>(Bird& another)override {
        return (this->altitude > another.getAltitude() ? *this : another);
	}
};
class Standard : public Dog{
public: 
    Standard(int weight, string name, int happniess) : Dog(weight, name, happniess) {}

    void getHappniess() override {
        cout<<"[" << name << "] 의 행복도는 [" << happiness << "] 입니다."<<endl;
    }
    void upHappiness() override {
        happiness += 40;
    }
};
/* Task */
// main() { Dog [] -> for(), Bird [] -> for() }
int main() {
	Dog *dog[] = {
		new Toy(3, "초코", 50),
		new Poodle(6, "마루", 40),
		new Standard(15, "라떼", 45)};

	Bird *bird[] = {
		new Vulture(70, "대머리 독수리", 100),
		new Swallow(30, "은혜 갚는 제비", 80),
		new Chicken(10, "토종닭", 10)};

	for (int i = 0; i < 3; i++){
        cout<<endl;
		dog[i]->eat();
		dog[i]->action(i);
		dog[i]->upHappiness();
		dog[i]->getHappniess();
	}

	for (int i = 0; i < 3; i++){
        cout<<endl;
		bird[i]->eat();
		bird[i]->action(i*10);
	}
    cout<<"\n가장 높이 나는 새는 "<<(*bird[0]>*bird[1]>*bird[2]).name<<" 입니다."<<endl;
}