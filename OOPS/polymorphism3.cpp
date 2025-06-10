#include <iostream>
#include<vector>
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
class Cat : public Animal{
    public:

    void speak(){
        cout<<"Meow"<<endl;
    }
};

int main(){
    Animal *p;
    vector<Animal*> animals;
    animals.push_back(new Dog());//we can have n number of classes therfor we need to these procedure not directy difing using the object defing method
    animals.push_back(new Cat());
    animals.push_back(new Animal());
    animals.push_back(new Dog());

    for (int i = 0; i < animals.size(); i++)
    {
        p=animals[i];
        p->speak();
    }
    

   
}