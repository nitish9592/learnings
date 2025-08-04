// knapsack_bottem_up.cpp iitrative tabulation
// This file implements the bottom-up dynamic programming solution for the 0/1 Knapsack problem
// It builds a DP table iteratively to find the maximum value that can be obtained with the given weights and values.
// The function `knapsackTab` initializes the DP table and iteratively fills it based on the choices of including or excluding each item.
// It is an iterative solution that explores both including and excluding each item.
#include <bits/stdc++.h>
using namespace std;


int knapsackTab(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base Case: Fill first row
    for (int w = wt[0]; w <= W; w++)
        dp[0][w] = val[0];

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notTake = dp[i - 1][w];
            int take = INT_MIN;
            if (wt[i] <= w)
                take = val[i] + dp[i - 1][w - wt[i]];
            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n - 1][W];
}

int main() {
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int W = 50;
    cout << "Maximum Value (Tabulation): " << knapsackTab(wt, val, W) << endl;
    return 0;
}
