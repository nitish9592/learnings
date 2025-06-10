#include <iostream>//BASICS OF CLASS
using namespace std;

class student {
    public://to make  the data members accessible
    string name ;
    int age;
    int gender;

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
    cout<<"enter NAME:";
    cin>>arr[i].name;         //OR USE THESE SYnTEX
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