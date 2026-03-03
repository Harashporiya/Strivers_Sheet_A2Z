#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base Case
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
};

int main() {
    Solution obj;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (obj.isSubsetSum(arr, sum))
        cout << "Subset exists";
    else
        cout << "Subset does not exist";

    return 0;
}