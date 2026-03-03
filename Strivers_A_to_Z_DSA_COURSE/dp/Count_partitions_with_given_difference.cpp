#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =====================================================
    // 1️⃣ PURE RECURSION
    // =====================================================
    int solveRec(int ind, vector<int>& arr, int target) {
        if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }

        int notTake = solveRec(ind - 1, arr, target);
        int take = 0;

        if (arr[ind] <= target)
            take = solveRec(ind - 1, arr, target - arr[ind]);

        return take + notTake;
    }

    int countPartitionsRecursion(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum + d) % 2 != 0 || d > totalSum)
            return 0;

        int s1 = (totalSum + d) / 2;

        return solveRec(arr.size() - 1, arr, s1);
    }


    // =====================================================
    // 2️⃣ MEMOIZATION
    // =====================================================
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

        if (arr[ind] <= target)
            take = solveMemo(ind - 1, arr, target - arr[ind], dp);

        return dp[ind][target] = take + notTake;
    }

    int countPartitionsMemo(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum + d) % 2 != 0 || d > totalSum)
            return 0;

        int s1 = (totalSum + d) / 2;

        vector<vector<int>> dp(arr.size(),
                               vector<int>(s1 + 1, -1));

        return solveMemo(arr.size() - 1, arr, s1, dp);
    }


    // =====================================================
    // 3️⃣ TABULATION (2D DP)
    // =====================================================
    int countPartitionsTabulation(vector<int>& arr, int d) {

        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum + d) % 2 != 0 || d > totalSum)
            return 0;

        int s1 = (totalSum + d) / 2;

        vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= s1)
            dp[0][arr[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= s1; target++) {

                int notTake = dp[ind - 1][target];
                int take = 0;

                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];

                dp[ind][target] = take + notTake;
            }
        }

        return dp[n - 1][s1];
    }


    // =====================================================
    // 4️⃣ SPACE OPTIMIZED (1D DP)
    // =====================================================
    int countPartitionsSpaceOptimized(vector<int>& arr, int d) {

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum + d) % 2 != 0 || d > totalSum)
            return 0;

        int s1 = (totalSum + d) / 2;

        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;

        for (int num : arr) {
            for (int target = s1; target >= num; target--) {
                dp[target] += dp[target - num];
            }
        }

        return dp[s1];
    }
};


// =====================================================
// MAIN FUNCTION (No User Input)
// =====================================================
int main() {

    Solution obj;

    // Hardcoded test case
    vector<int> arr = {1, 1, 2, 3};
    int d = 1;

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\nDifference: " << d << endl;

    cout << "\nUsing Recursion: "
         << obj.countPartitionsRecursion(arr, d) << endl;

    cout << "Using Memoization: "
         << obj.countPartitionsMemo(arr, d) << endl;

    cout << "Using Tabulation: "
         << obj.countPartitionsTabulation(arr, d) << endl;

    cout << "Using Space Optimized: "
         << obj.countPartitionsSpaceOptimized(arr, d) << endl;

    return 0;
}