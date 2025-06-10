
#include <iostream>//reverse a string word by word
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);//putting the element at bottom
        return;
    }
    int topele =st.top();

    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);//pushing the rest of element back
}
void reverse(stack<int> &st ){
    if(st.empty()){
        return;
    }
    int ele=st.top();//store the top element 

    st.pop();
    reverse(st);//call for rest of the stack
    insertAtBottom(st,ele);//to insert the topmost element at bottom to reverse it

}
int main(){
 stack<int> st ;
 st.push(6);
 st.push(4);
 st.push(5);
 reverse (st);
 while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
 }

}