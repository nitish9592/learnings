#include <iostream>//USING A CONSTRUCTORs
using namespace std;

class student {
     string name ;//
    public://
    int age;
    int gender;
    student(){
        cout<<"defaultConstructor"<<endl;

    }//DEFAULT CONSTRUCTOR

    student(string s,int a ,int g){
        cout<<"parameterized constructor"<<endl;

        name =s;
        age =a;
        gender=g;
    }//  PAARAMETERIZED CONSTRUCTOR;;

    student(student &a){
        cout<<"copy constructor "<<endl;
        name =a.name;
        age =a.age;
        gender =a.gender;
    }//COPY CONSTRUCTOR;
    void setName(string s){//this is called setter function
        name =s;//s will be stored in attribute name;
    }
    void getName(){
        cout<<name<<endl;//getter funtion 
    }

void printInfo(){
    cout<<"name = ";
    cout<<name<<endl;
    cout<<"age = ";
    cout<<age<<endl;
    cout<<"gender = ";
    cout<<gender<<endl;
    
}


};

int main (){


student a("nitish",21,1);
student b;
student c =a;
return 0;
}
