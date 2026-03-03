#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    // =====================================================
    // 1️⃣ PURE RECURSION
    // =====================================================
    int solveRec(int i, int amount, vector<int>& coins) {
        if (i == coins.size()) {
            return (amount == 0);
        }

        int notPick = solveRec(i + 1, amount, coins);
        int pick = 0;

        if (amount >= coins[i]) {
            pick = solveRec(i, amount - coins[i], coins);
        }

        return (notPick + pick) % MOD;
    }

    int changeRecursion(int amount, vector<int>& coins) {
        return solveRec(0, amount, coins);
    }


    // =====================================================
    // 2️⃣ MEMOIZATION (TOP-DOWN)
    // =====================================================
    int solveMemo(int i, int amount, vector<int>& coins,
                  vector<vector<int>>& dp) {

        if (i == coins.size()) {
            return (amount == 0);
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int notPick = solveMemo(i + 1, amount, coins, dp);
        int pick = 0;

        if (amount >= coins[i]) {
            pick = solveMemo(i, amount - coins[i], coins, dp);
        }

        return dp[i][amount] = (notPick + pick) % MOD;
    }

    int changeMemo(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),
                               vector<int>(amount + 1, -1));

        return solveMemo(0, amount, coins, dp);
    }


    // =====================================================
    // 3️⃣ TABULATION (BOTTOM-UP 2D)
    // =====================================================
    int changeTabulation(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n + 1,
                               vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 0; a <= amount; a++) {

                int notPick = dp[i + 1][a];
                int pick = 0;

                if (a >= coins[i])
                    pick = dp[i][a - coins[i]];

                dp[i][a] = (notPick + pick) % MOD;
            }
        }

        return dp[0][amount];
    }


    // =====================================================
    // 4️⃣ SPACE OPTIMIZED (1D DP – BEST)
    // =====================================================
    int changeSpaceOptimized(int amount, vector<int>& coins) {

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int a = coin; a <= amount; a++) {
                dp[a] = (dp[a] + dp[a - coin]) % MOD;
            }
        }

        return dp[amount];
    }
};


// =====================================================
// MAIN FUNCTION (No User Input)
// =====================================================
int main() {

    Solution obj;

    // Hardcoded test case
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Coins: ";
    for (int c : coins)
        cout << c << " ";

    cout << "\nAmount: " << amount << endl;

    cout << "\nUsing Recursion: "
         << obj.changeRecursion(amount, coins) << endl;

    cout << "Using Memoization: "
         << obj.changeMemo(amount, coins) << endl;

    cout << "Using Tabulation: "
         << obj.changeTabulation(amount, coins) << endl;

    cout << "Using Space Optimized: "
         << obj.changeSpaceOptimized(amount, coins) << endl;

    return 0;
}