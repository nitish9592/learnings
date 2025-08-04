
#include<iostream>
#include <vector>
#include <stack>

using namespace std;
/*BRUTE FORCE
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> maxL(n), maxR(n);
    int h20 = 0;

    // Compute maxL array (max height from left to current position)
    maxL[0] = height[0];
    for (int i = 1; i < n; i++) {
        maxL[i] = max(maxL[i - 1], height[i]);
    }

    // Compute maxR array (max height from right to current position)
    maxR[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxR[i] = max(maxR[i + 1], height[i]);
    }

    // Calculate trapped water
    for (int i = 0; i < n; i++) {
        h20 += min(maxL[i], maxR[i]) - height[i];
    }

    return h20;
}
*/
//USING STACK
int trap(vector<int> a)
{
    stack<int> st;
    int n=a.size(),ans=0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()]<a[i]){
            int cur =st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff = i- st.top()-1;
            ans+= min( a[st.top()],a[i])-a[cur]*diff;
        }
        st.push(i);
        
        
        /* code */
    }
    
return ans;
}
int main(){
    vector<int> height ={4,2,0,3,2,5};
    cout<< trap(height);
}
