
#include <iostream>
#include <stack>
using namespace std;

//QUEUE USING STACK
/*
#define n 100
class queue {
    int *arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x){
        if(back ==n-1){
            cout<<"queue Overflow"<<endl;
            return;
        }
        
        back++;
        arr[back]=x;
        
        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front==-1 ||front>back){
            cout<<"queue empty"<<endl;
        }
        front++;
    }

    int peek(){
        if(front==-1 ||front>back){
            return -1;
            
        }
        else{return arr[front];}
    }

    void isEmpty(){
        if(front==-1 ||front>back){
            cout<<"queue empty"<<endl;
        }
    }

};
*/

//QUEUE USING LL


class node {
    public:
    int data;
    node* next;

    node(int val){
        data =val;
        next =NULL;

    }

};
class queue{
    node*front;
    node*back;

    public:
    queue(){
        front =NULL;
        back =NULL;
        
    }

    void push(int x){
            node* n =new node(x);
            if(front==NULL){
                front =n;
                back =n;
                return;
            }
            back->next=n;
            back =n;
    }

    void pop(){
        if(front ==NULL){
            cout<<"queue underflow"<<endl;
            return;
        }

        node* todelete = front;
        front=front->next;
        delete todelete;
    }

    int peek(){
        if(front ==NULL){
            cout<<"queue underflow"<<endl;
            return -1;
        }

        return front->data;
    }

    bool empty(){
        if(front ==NULL){
            
            return true;
        }
        return false;
    }
};




int main()

{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    
}
