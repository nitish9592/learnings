#include <iostream>
using namespace std;

#define n 100//for pridefined value of n
class stack{
    int *arr;//dinamically
    int top;

    public:
    stack(){//constructor
        arr =new int[n];
        top = -1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"stack overflow"<<endl;
            return ;
        }
        top++;//first increment then put val
        arr[top]=x;

    }
    
    void pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top ==-1;
    }


};

int main(){
    stack st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.isEmpty()<<endl;


}