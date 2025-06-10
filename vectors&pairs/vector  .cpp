#include <iostream>
#include <vector>//header file required
using namespace std;
int main()
{

    vector<int> v;
    v.push_back(1);//insert element at end
    v.push_back(2);
    v.push_back(3);//1 2 3

    for(int i =0;i<v.size();i++ ){
        cout<<v[i]<<endl;
    }//normal irrating

    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }//itrrating using vector itrator

    for(auto element:v){
        cout<<element<<endl; 
    }//auto keyword compiler dcided itself the data type

    v.pop_back();//1 2 (delete last element)

    vector<int> v2(3,50);//50 50 50

    swap (v,v2);
    for(auto element:v){
        cout<<element<<endl; 
    }
    for(auto element:v2){
        cout<<element<<endl; 
    }
    //do check other functions of vectors at c++.com



return 0;
}
