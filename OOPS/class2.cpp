#include <iostream>//TO ACCESS A PRIVATE ELMENT
using namespace std;

class student {
     string name ;//here this element is private!!!!
    public://to make  the data members accessible
    int age;
    int gender;
    void setName(string s){//this is called setter function
        name =s;//s will be stored in attribute name;
    }
    void getName(){
        cout<<name<<endl;//getter funtion 
    }

void printInfo(){
    cout<<"name =";
    cout<<name<<endl;
    cout<<"age =";
    cout<<age<<endl;
    cout<<"gender =";
    cout<<gender<<endl;
    
}


};

int main (){


//student a;
//a.name='tim';    EITHER USE THIS TO DECLEAR THE OBJECT
//a.age=54;
//a.gender=1;

student arr[3];
for (int i=0;i<3;i++){
    string s;//to take input in that private element

    cout<<"enter NAME:";
    cin>>s;
    arr[i].setName(s);  //take vale       //OR USE THESE SYnTEX
    cout<<"enter AGE:";
    cin>>arr[i].age;
    cout<<"enter gender:";
    cin>>arr[i].gender;
}
for (int i=0;i<3;i++){
    arr[i].printInfo();
}
return 0;
}
