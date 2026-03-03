#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =========================
    // 1️⃣ Simple Recursion
    // =========================
    bool solveRec(int ind, vector<int>& arr, int target) {
        if (target == 0) return true;
        if (ind == 0) return (arr[0] == target);

        bool notTake = solveRec(ind - 1, arr, target);
        bool take = false;

        if (target >= arr[ind])
            take = solveRec(ind - 1, arr, target - arr[ind]);

        return take || notTake;
    }

    bool subsetSumRecursion(vector<int>& arr, int sum) {
        int n = arr.size();
        return solveRec(n - 1, arr, sum);
    }


    // =========================
    // 2️⃣ Memoization (Top Down)
    // =========================
    bool solveMemo(int ind, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return (arr[0] == target);

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = solveMemo(ind - 1, arr, target, dp);
        bool take = false;

        if (target >= arr[ind])
            take = solveMemo(ind - 1, arr, target - arr[ind], dp);

        return dp[ind][target] = take || notTake;
    }

    bool subsetSumMemo(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solveMemo(n - 1, arr, sum, dp);
    }


    // =========================
    // 3️⃣ Tabulation (Bottom Up)
    // =========================
    bool subsetSumTabulation(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {

                bool notTake = dp[i - 1][target];
                bool take = false;

                if (target >= arr[i])
                    take = dp[i - 1][target - arr[i]];

                dp[i][target] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }


    // =========================
    // 4️⃣ Space Optimized
    // =========================
    bool subsetSumSpaceOptimized(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);

        prev[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            vector<bool> curr(sum + 1, false);
            curr[0] = true;

            for (int target = 1; target <= sum; target++) {

                bool notTake = prev[target];
                bool take = false;

                if (target >= arr[i])
                    take = prev[target - arr[i]];

                curr[target] = take || notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }
};


// =========================
// MAIN FUNCTION
// =========================
int main() {

    Solution obj;

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout << "Recursion: ";
    cout << (obj.subsetSumRecursion(arr, sum) ? "True" : "False") << endl;

    cout << "Memoization: ";
    cout << (obj.subsetSumMemo(arr, sum) ? "True" : "False") << endl;

    cout << "Tabulation: ";
    cout << (obj.subsetSumTabulation(arr, sum) ? "True" : "False") << endl;

    cout << "Space Optimized: ";
    cout << (obj.subsetSumSpaceOptimized(arr, sum) ? "True" : "False") << endl;

    return 0;
}