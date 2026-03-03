#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =====================================================
    // 1️⃣ PURE RECURSION
    // =====================================================
    int solveRec(int i, int sum, vector<int>& nums) {
        if (i == 0) {
            if (sum == 0 && nums[0] == 0) return 2;
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }

        int notPick = solveRec(i - 1, sum, nums);
        int pick = 0;

        if (nums[i] <= sum)
            pick = solveRec(i - 1, sum - nums[i], nums);

        return pick + notPick;
    }

    int findTargetSumWaysRec(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int s1 = (totalSum + target) / 2;

        return solveRec(nums.size() - 1, s1, nums);
    }


    // =====================================================
    // 2️⃣ MEMOIZATION
    // =====================================================
    int solveMemo(int i, int sum, vector<int>& nums,
                  vector<vector<int>>& dp) {

        if (i == 0) {
            if (sum == 0 && nums[0] == 0) return 2;
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int notPick = solveMemo(i - 1, sum, nums, dp);
        int pick = 0;

        if (nums[i] <= sum)
            pick = solveMemo(i - 1, sum - nums[i], nums, dp);

        return dp[i][sum] = pick + notPick;
    }

    int findTargetSumWaysMemo(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int s1 = (totalSum + target) / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(s1 + 1, -1));

        return solveMemo(nums.size() - 1, s1, nums, dp);
    }


    // =====================================================
    // 3️⃣ TABULATION
    // =====================================================
    int findTargetSumWaysTab(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int s1 = (totalSum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= s1)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= s1; sum++) {

                int notPick = dp[i - 1][sum];
                int pick = 0;

                if (nums[i] <= sum)
                    pick = dp[i - 1][sum - nums[i]];

                dp[i][sum] = pick + notPick;
            }
        }

        return dp[n - 1][s1];
    }


    // =====================================================
    // 4️⃣ SPACE OPTIMIZED (BEST)
    // =====================================================
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int s1 = (totalSum + target) / 2;

        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int sum = s1; sum >= num; sum--) {
                dp[sum] += dp[sum - num];
            }
        }

        return dp[s1];
    }
};


// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    Solution obj;

    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    cout << "Using Recursion: "
         << obj.findTargetSumWaysRec(nums, target) << endl;

    cout << "Using Memoization: "
         << obj.findTargetSumWaysMemo(nums, target) << endl;

    cout << "Using Tabulation: "
         << obj.findTargetSumWaysTab(nums, target) << endl;

    cout << "Using Space Optimized: "
         << obj.findTargetSumWays(nums, target) << endl;

    return 0;
}