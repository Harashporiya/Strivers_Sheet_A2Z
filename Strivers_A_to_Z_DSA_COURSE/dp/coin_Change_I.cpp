#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =====================================================
    // 1️⃣ PURE RECURSION
    // =====================================================
    int solveRec(int i, int amount, vector<int>& coins) {
        if (i == coins.size()) {
            return (amount == 0) ? 0 : INT_MAX;
        }

        int notPick = solveRec(i + 1, amount, coins);

        int pick = INT_MAX;
        if (amount >= coins[i]) {
            int res = solveRec(i, amount - coins[i], coins);
            if (res != INT_MAX)
                pick = 1 + res;
        }

        return min(pick, notPick);
    }

    int coinChangeRecursion(vector<int>& coins, int amount) {
        int ans = solveRec(0, amount, coins);
        return (ans == INT_MAX) ? -1 : ans;
    }


    // =====================================================
    // 2️⃣ MEMOIZATION (TOP-DOWN)
    // =====================================================
    int solveMemo(int i, int amount, vector<int>& coins,
                  vector<vector<int>>& dp) {

        if (i == coins.size()) {
            return (amount == 0) ? 0 : INT_MAX;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int notPick = solveMemo(i + 1, amount, coins, dp);

        int pick = INT_MAX;
        if (amount >= coins[i]) {
            int res = solveMemo(i, amount - coins[i], coins, dp);
            if (res != INT_MAX)
                pick = 1 + res;
        }

        return dp[i][amount] = min(pick, notPick);
    }

    int coinChangeMemo(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),
                               vector<int>(amount + 1, -1));

        int ans = solveMemo(0, amount, coins, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }


    // =====================================================
    // 3️⃣ TABULATION (BOTTOM-UP 2D)
    // =====================================================
    int coinChangeTabulation(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n + 1,
                               vector<int>(amount + 1, INT_MAX));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 0; a <= amount; a++) {

                int notPick = dp[i + 1][a];
                int pick = INT_MAX;

                if (a >= coins[i] && dp[i][a - coins[i]] != INT_MAX)
                    pick = 1 + dp[i][a - coins[i]];

                dp[i][a] = min(pick, notPick);
            }
        }

        int ans = dp[0][amount];
        return (ans == INT_MAX) ? -1 : ans;
    }


    // =====================================================
    // 4️⃣ SPACE OPTIMIZED (1D DP – BEST)
    // =====================================================
    int coinChangeSpaceOptimized(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int coin : coins) {
            for (int a = coin; a <= amount; a++) {
                if (dp[a - coin] != INT_MAX)
                    dp[a] = min(dp[a], 1 + dp[a - coin]);
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};


// =====================================================
// MAIN FUNCTION (No User Input)
// =====================================================
int main() {

    Solution obj;

    // Hardcoded test case
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Coins: ";
    for (int c : coins)
        cout << c << " ";

    cout << "\nAmount: " << amount << endl;

    cout << "\nUsing Recursion: "
         << obj.coinChangeRecursion(coins, amount) << endl;

    cout << "Using Memoization: "
         << obj.coinChangeMemo(coins, amount) << endl;

    cout << "Using Tabulation: "
         << obj.coinChangeTabulation(coins, amount) << endl;

    cout << "Using Space Optimized: "
         << obj.coinChangeSpaceOptimized(coins, amount) << endl;

    return 0;
}