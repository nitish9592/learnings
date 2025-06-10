#include "bits/stdc++.h"

using namespace std;

long long merge(vector<long long>& arr,int l, int mid, int r){
int n1 = mid - l+1;
int n2 = r - mid;
vector<long long > a(n1),b(n2);
for(int i=0;i<n1;i++){
    a[i]=arr[l+i];
    
}
for(int j=0;j<n2;j++){
    b[j]=arr[mid+j+1];
    
}
long long  inv =0;
int i =0, j=0,k=l;
while(i<n1 and j< n2){
    if(a[i]<=b[j]){
        arr[k]=a[i];
        k++;i++;
    }
    else{
        arr[k]=b[j];
        inv +=n1-i;
        k++;i++;

    }
}
while(i<n1){
    arr[k]= a[i];
    k++;i++;
}
while(j<n2){
    arr[k]=b[j];
    k++;
    j++;
}
return inv;
}
long long  mergeSort (vector<long long>& arr,int l, int r){
    long long inv =0;
    if(l<r){
        int mid =(l+r)/2;
        inv += mergeSort(arr,l,mid);
        inv += mergeSort(arr, mid+1,r);
        inv += merge(arr,l,mid,r);
    }
    return inv;
}

int32_t main (){
     int n ;cin>>n;
     vector<long long> arr(n);
     for(int i=0;i<n ;i++){
         cin>>arr[i];

     }
   
    cout<<mergeSort(arr, 0, n-1);
    return 0;


   
    

}
