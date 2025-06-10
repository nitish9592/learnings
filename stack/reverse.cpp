#include <iostream>//reverse a string word by word
#include <stack>
using namespace std;
void reverse(string s){
    
    stack <string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string word ="";//one element to insert at top of the stack

        while(s[i]!=' '&&i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);//pushing one word when space is reached
    }
    
    while(!st.empty()){
        
        cout<<st.top()<<" ";//display top
        st.pop();//remove top

    }cout<<endl;
    

}
int main(){
    string s="hey guyz, how are you  people";
    
    
    reverse(s);

}