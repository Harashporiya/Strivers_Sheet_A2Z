#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ==============================
    // 1️⃣ Recursion
    // ==============================
    bool solveRec(int i, vector<int>& nums, int target) {
        if (target == 0) return true;
        if (i == nums.size()) return false;

        bool notTake = solveRec(i + 1, nums, target);
        bool take = false;

        if (target >= nums[i])
            take = solveRec(i + 1, nums, target - nums[i]);

        return take || notTake;
    }

    bool canPartitionRec(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        return solveRec(0, nums, sum / 2);
    }


    // ==============================
    // 2️⃣ Memoization (Top Down)
    // ==============================
    bool solveMemo(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == nums.size()) return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool notTake = solveMemo(i + 1, nums, target, dp);
        bool take = false;

        if (target >= nums[i])
            take = solveMemo(i + 1, nums, target - nums[i], dp);

        return dp[i][target] = take || notTake;
    }

    bool canPartitionMemo(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solveMemo(0, nums, target, dp);
    }


    // ==============================
    // 3️⃣ Tabulation (Bottom Up)
    // ==============================
    bool canPartitionTab(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {

                bool notTake = dp[i - 1][t];
                bool take = false;

                if (t >= nums[i])
                    take = dp[i - 1][t - nums[i]];

                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }


    // ==============================
    // 4️⃣ Space Optimized
    // ==============================
    bool canPartitionSpaceOpt(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<bool> prev(target + 1, false);
        prev[0] = true;

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true;

            for (int t = 1; t <= target; t++) {

                bool notTake = prev[t];
                bool take = false;

                if (t >= nums[i])
                    take = prev[t - nums[i]];

                curr[t] = take || notTake;
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

    vector<int> nums = {1, 5, 11, 5};

    cout << "Recursion: "
         << (obj.canPartitionRec(nums) ? "True" : "False") << endl;

    cout << "Memoization: "
         << (obj.canPartitionMemo(nums) ? "True" : "False") << endl;

    cout << "Tabulation: "
         << (obj.canPartitionTab(nums) ? "True" : "False") << endl;

    cout << "Space Optimized: "
         << (obj.canPartitionSpaceOpt(nums) ? "True" : "False") << endl;

    return 0;
}