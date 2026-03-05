#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /*---------------------------------------------------
      1️⃣ Memoization (Top-Down DP) - O(n^2)
    ---------------------------------------------------*/
    int f(int ind, int pre_ind, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();

        if(ind == n)
            return 0;

        if(dp[ind][pre_ind + 1] != -1)
            return dp[ind][pre_ind + 1];

        int len = f(ind + 1, pre_ind, nums, dp);  // not take

        if(pre_ind == -1 || nums[ind] > nums[pre_ind])
            len = max(len, 1 + f(ind + 1, ind, nums, dp)); // take

        return dp[ind][pre_ind + 1] = len;
    }

    int lengthOfLIS_Memo(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }

    /*---------------------------------------------------
      2️⃣ Tabulation (Bottom-Up DP) - O(n^2)
    ---------------------------------------------------*/
    int lengthOfLIS_Tab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int ind = n - 1; ind >= 0; ind--){
            for(int pre_ind = ind - 1; pre_ind >= -1; pre_ind--){

                int len = dp[ind + 1][pre_ind + 1]; // not take

                if(pre_ind == -1 || nums[ind] > nums[pre_ind])
                    len = max(len, 1 + dp[ind + 1][ind + 1]); // take

                dp[ind][pre_ind + 1] = len;
            }
        }
        return dp[0][0];
    }

    /*---------------------------------------------------
      3️⃣ Optimal (Binary Search) - O(n log n)
    ---------------------------------------------------*/
    int binarySearch(vector<int>& a, int target){
        int l = 0, h = a.size() - 1;

        while(l <= h){
            int mid = l + (h - l) / 2;

            if(a[mid] == target)
                return mid;
            else if(a[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;  // lower bound position
    }

    int lengthOfLIS_Optimal(vector<int>& nums) {
        vector<int> res;

        for(int num : nums){
            if(res.empty() || res.back() < num){
                res.push_back(num);
            } else {
                int ind = binarySearch(res, num);
                res[ind] = num;
            }
        }
        return res.size();
    }
};


/*---------------------------------------------------
                    MAIN FUNCTION
---------------------------------------------------*/
int main() {

    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "\nLIS using Memoization: " 
         << obj.lengthOfLIS_Memo(nums) << endl;

    cout << "LIS using Tabulation: " 
         << obj.lengthOfLIS_Tab(nums) << endl;

    cout << "LIS using Optimal (Binary Search): " 
         << obj.lengthOfLIS_Optimal(nums) << endl;

    return 0;
}