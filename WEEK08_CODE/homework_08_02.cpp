#include <iostream>

class Strategy{
public:
    virtual ~Strategy() {}
    virtual void execute(int num1, int num2)=0;
};

class Context{
private:
    Strategy *_strategy;
public:
    Context(Strategy *strategy) : _strategy(strategy){}
    ~Context(){ delete this->_strategy;}
    void set_strategy(Strategy *strategy){
        delete this->_strategy;
        this->_strategy = strategy;
    }
    void executeStrategy(int num1, int num2){
        this->_strategy->execute(num1, num2);
    }
};

class OperationAdd : public Strategy{
public:
    void execute(int num1, int num2) override {
        int result = num1 + num2;
        std::cout<<num1<<" + "<<num2<<" = "<<result<<std::endl;
    }
};
class OperationSubtract : public Strategy{
public:
    void execute(int num1, int num2) override {
        int result = num1 - num2;
        std::cout<<num1<<" - "<<num2<<" = "<<result<<std::endl;
    }
};
class OperationMultiply : public Strategy{
public:
    void execute(int num1, int num2) override {
        int result = num1 * num2;
        std::cout<<num1<<" * "<<num2<<" = "<<result<<std::endl;
    }
};

int main(){
    Context *context = new Context(new OperationAdd());
    context->executeStrategy(10, 5);
    context = new Context(new OperationSubtract());
    context->executeStrategy(10, 5);
    context = new Context(new OperationMultiply());
    context->executeStrategy(10, 5);

}