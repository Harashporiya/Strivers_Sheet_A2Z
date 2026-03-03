#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =====================================================
    // 1️⃣ PURE RECURSION
    // =====================================================
    int solveRec(int ind, int N, vector<int>& p) {
        if (ind == 0) {
            return N * p[0];
        }

        int notTake = solveRec(ind - 1, N, p);
        int take = INT_MIN;

        int rodLength = ind + 1;

        if (rodLength <= N) {
            take = p[ind] + solveRec(ind, N - rodLength, p);
        }

        return max(notTake, take);
    }

    int cutRodRec(vector<int>& p) {
        int n = p.size();
        return solveRec(n - 1, n, p);
    }


    // =====================================================
    // 2️⃣ MEMOIZATION (TOP-DOWN)
    // =====================================================
    int solveMemo(int ind, int N, vector<int>& p,
                  vector<vector<int>>& dp) {

        if (ind == 0)
            return N * p[0];

        if (dp[ind][N] != -1)
            return dp[ind][N];

        int notTake = solveMemo(ind - 1, N, p, dp);
        int take = INT_MIN;

        int rodLength = ind + 1;

        if (rodLength <= N)
            take = p[ind] + solveMemo(ind, N - rodLength, p, dp);

        return dp[ind][N] = max(notTake, take);
    }

    int cutRodMemo(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveMemo(n - 1, n, p, dp);
    }


    // =====================================================
    // 3️⃣ TABULATION (2D DP)
    // =====================================================
    int cutRodTab(vector<int>& p) {

        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int N = 0; N <= n; N++)
            dp[0][N] = N * p[0];

        for (int ind = 1; ind < n; ind++) {
            for (int N = 0; N <= n; N++) {

                int notTake = dp[ind - 1][N];
                int take = INT_MIN;

                int rodLength = ind + 1;

                if (rodLength <= N)
                    take = p[ind] + dp[ind][N - rodLength];

                dp[ind][N] = max(notTake, take);
            }
        }

        return dp[n - 1][n];
    }


    // =====================================================
    // 4️⃣ SPACE OPTIMIZED (1D DP – BEST)
    // =====================================================
    int cutRod(vector<int>& p) {

        int n = p.size();
        vector<int> dp(n + 1, 0);

        for (int N = 0; N <= n; N++)
            dp[N] = N * p[0];

        for (int ind = 1; ind < n; ind++) {
            for (int N = 0; N <= n; N++) {

                int notTake = dp[N];
                int take = INT_MIN;

                int rodLength = ind + 1;

                if (rodLength <= N)
                    take = p[ind] + dp[N - rodLength];

                dp[N] = max(notTake, take);
            }
        }

        return dp[n];
    }
};


// =====================================================
// MAIN FUNCTION (No User Input)
// =====================================================
int main() {

    Solution obj;

    // Hardcoded test case
    vector<int> price = {2, 5, 7, 8, 10};

    cout << "Maximum Profit (Recursion): "
         << obj.cutRodRec(price) << endl;

    cout << "Maximum Profit (Memoization): "
         << obj.cutRodMemo(price) << endl;

    cout << "Maximum Profit (Tabulation): "
         << obj.cutRodTab(price) << endl;

    cout << "Maximum Profit (Space Optimized): "
         << obj.cutRod(price) << endl;

    return 0;
}