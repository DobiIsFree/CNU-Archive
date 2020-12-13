#include <iostream>

class SetValue{
    int x,y;
    public:
        void setX(int newX){
            x = newX;
        }
        void setY(int newY){
            y = newY;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
};

int main(){
    SetValue obj;
    obj.setX(33);
    obj.setY(44);

    std::cout<<"X ="<< obj.getX()<<" , Y = "<<obj.getY()<<std::endl;
    system("pause");
    return 0;
}
