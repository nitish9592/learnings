#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

    bool myCompare(pair<int,int> p1, pair<int,int> p2){

        return p1.first<p2.first;
    }


int main (){
//apna college c++ vid--50

    //pair <int, char>;
    //p.first =3;
    //p.second ='f';//GENRAL SYNTAX OF A PAIR


//Q--> reducing the given arr
//ex-  arr{10,16,7,14,5,3,12,9}
//   index- 0 1  2 3  4 5 6  7
//AFTER REDUCING;
//     arr{4,7,2,6,1,0,5,3}
//   index-0 1 2 3 4 5 6 7

   


    int arr[]={10, 16, 7, 14,5,3,2,9};
    vector< pair<int,int> > v;  //defining a vectors of pairs                 

    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){    //Dividing the size of the array by the size of a single element gives the number of elements in the array, or its length. 
    //pair<int,int> p;
    //p.first=arr[i];
    //p.second=i;
    //v.push_back(p); 

    //OR

    v.push_back(make_pair(arr[i],i)); //direct fun for makeing and then adding pairs to the vector

    }

    sort(v.begin() ,v.end() ,myCompare);
    for(int i ;i<v.size();i++){

        arr[v[i].second]=i;

    }

    for(int i ;i<v.size();i++){

        cout<<arr[i] <<" ";
        
    }



    return 0;
}