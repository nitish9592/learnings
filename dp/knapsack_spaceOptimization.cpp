// Knapsack Problem - Space Optimized Version
// This code implements the 0/1 Knapsack problem using space optimization.
// It uses a single-dimensional DP array to reduce space complexity from O(nW) to O
// (W), where n is the number of items and W is the maximum weight capacity.
#include <bits/stdc++.h>
using namespace std;

int knapsackSpaceOpt(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);

    // Base Case: First item
    for (int w = wt[0]; w <= W; w++)
        dp[w] = val[0];

    for (int i = 1; i < n; i++) {
        for (int w = W; w >= 0; w--) {  // Iterate in reverse
            int notTake = dp[w];
            int take = INT_MIN;
            if (wt[i] <= w)
                take = val[i] + dp[w - wt[i]];
            dp[w] = max(take, notTake);
        }
    }
    return dp[W];
}

int main() {
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int W = 50;
    cout << "Maximum Value (Space Optimized): " << knapsackSpaceOpt(wt, val, W) << endl;
    return 0;
}
