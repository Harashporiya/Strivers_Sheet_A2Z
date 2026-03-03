#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ==============================
    // 1. PURE RECURSION
    // ==============================
    int solveRec(int ind, vector<int>& arr, int target) {
        if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }

        int notTake = solveRec(ind - 1, arr, target);
        int take = 0;
        if (arr[ind] <= target) {
            take = solveRec(ind - 1, arr, target - arr[ind]);
        }

        return take + notTake;
    }

    int perfectSumRecursion(vector<int>& arr, int target) {
        int n = arr.size();
        return solveRec(n - 1, arr, target);
    }


    // ==============================
    // 2. MEMOIZATION (TOP-DOWN DP)
    // ==============================
    int solveMemo(int ind, vector<int>& arr, int target,
                  vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = solveMemo(ind - 1, arr, target, dp);
        int take = 0;
        if (arr[ind] <= target) {
            take = solveMemo(ind - 1, arr, target - arr[ind], dp);
        }

        return dp[ind][target] = take + notTake;
    }

    int perfectSumMemo(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solveMemo(n - 1, arr, target, dp);
    }


    // ==============================
    // 3. TABULATION (BOTTOM-UP DP)
    // ==============================
    int perfectSumTabulation(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base case
        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= target; t++) {

                int notTake = dp[ind - 1][t];
                int take = 0;

                if (arr[ind] <= t)
                    take = dp[ind - 1][t - arr[ind]];

                dp[ind][t] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }


    // ==============================
    // 4. SPACE OPTIMIZED TABULATION
    // ==============================
    int perfectSumSpaceOptimized(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        if (arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= target; t++) {

                int notTake = prev[t];
                int take = 0;

                if (arr[ind] <= t)
                    take = prev[t - arr[ind]];

                curr[t] = take + notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};


// ==============================
// MAIN FUNCTION
// ==============================
int main() {

    Solution obj;

    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    cout << "\nUsing Recursion: "
         << obj.perfectSumRecursion(arr, target) << endl;

    cout << "Using Memoization: "
         << obj.perfectSumMemo(arr, target) << endl;

    cout << "Using Tabulation: "
         << obj.perfectSumTabulation(arr, target) << endl;

    cout << "Using Space Optimized DP: "
         << obj.perfectSumSpaceOptimized(arr, target) << endl;

    return 0;
}