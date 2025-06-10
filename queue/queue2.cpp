
#include <iostream>
#include <stack>
using namespace std;
//QUEUE USING STACK
/*
class queue {
    stack <int> s1;
    stack <int> s2;

    public:
        void push(int x){
            s1.push(x);
        }
        int pop(){
            if(s1.empty() and s2.empty()){//and can be used like this also
                cout<<"emty"<<endl;
                return -1;
            }
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int top = s2.top();
            s2.pop();
            return top;
        }

        int peek(){
            if(s1.empty() and s2.empty()){
                cout<<"emty"<<endl;
                return -1;
            }
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int top = s2.top();
            
            return top;
        }

        bool isEmpty(){
            if(s1.empty() and s2.empty()){
                return true;
            }
            return false;
        }
    
};
*/


//QUEUE USING ONLY ONE STACK
class queue {
    stack <int> s1;
    stack <int> s2;

    public:
        void push(int x){
            s1.push(x);
        }
        int pop(){//RECURSIVLY
            if(s1.empty() ){//base condition when there is only one element left in stack
                cout<<"emty"<<endl;
                return -1;
            }
            int x = s1.top();
            s1.pop();
            if(s1.empty()){
                return x;
            }
            int item =pop();
            s1.push(x);
            return item;


            
        }

        int peek(){
            if(s1.empty() ){//base condition when there is only one element left in stack
                cout<<"emty"<<endl;
                return -1;
            }
            int x = s1.top();
            
            if(s1.empty()){
                return x;
            }
            int item =pop();
            s1.push(x);
            return item;

        }

        bool isEmpty(){
            if(s1.empty() and s2.empty()){
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
