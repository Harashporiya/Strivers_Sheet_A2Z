#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    // DP table banate hai with (n+1) x (W+1) size
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table dp[][] bottom-up
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                // Include ya exclude karo item ko
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], 
                               dp[i - 1][w]);
            } else {
                // Item nahi le sakte
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n = 4;
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;

    cout << "Maximum value in knapsack = " << knapSack(W, wt, val, n) << endl;
    return 0;
}
