// knapsack_top_down.cpp recussive + memoization
// This code implements the 0/1 Knapsack problem using top-down dynamic programming (memo
// approach). It uses recursion with memoization to avoid redundant calculations.
// The function `knapsackMemo` initializes the memoization table and calls the recursive function.
// It returns the maximum value that can be obtained with the given weights and values.
// It is a recursive solution that explores both including and excluding each item.

#include <bits/stdc++.h>
using namespace std;

int knapsackRec(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    // Base case: No items or no capacity left
    if (i == 0) {
        if (wt[0] <= W) return val[0];
        return 0;
    }

    if (dp[i][W] != -1) return dp[i][W];

    // Exclude current item
    int notTake = knapsackRec(i - 1, W, wt, val, dp);

    // Include current item (only if it fits)
    int take = INT_MIN;
    if (wt[i] <= W)
        take = val[i] + knapsackRec(i - 1, W - wt[i], wt, val, dp);

    return dp[i][W] = max(take, notTake);
}

int knapsackMemo(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackRec(n - 1, W, wt, val, dp);
}

int main() {
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int W = 50;
    cout << "Maximum Value (Memoization): " << knapsackMemo(wt, val, W) << endl;
    return 0;
}
