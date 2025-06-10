#include <iostream>
using namespace std;
void permutation(string s,string ans){
    
    
    if(s.length()==0){
    cout<<ans;
    return;
    }
    for(int i=0;i<s.length() ;i++)
    {
     string ros = s.substr(0,i)+ s.substr(i+1);
     permutation(ros,ans);
   
    }

} 


int main()
{
 permutation("abcd"," ");
 
return 0;
}