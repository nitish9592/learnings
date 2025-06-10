#include <iostream>
using namespace std;
class Animal{
    public:

    virtual void speak(){
        cout<<"huhu"<<endl;
    }
};
class Dog : public Animal{
    public:

    void speak(){
        cout<<"bark"<<endl;
    }
};

int main(){
    Animal *ptr;
    ptr = new Dog();//this will allocate memory to dog() object in run time ,dynamically allocated (heap data structure)
    ptr->speak();//if we dont use vertual keyword then this will point to animal not dog and the result will be huhu

    return 0;
}