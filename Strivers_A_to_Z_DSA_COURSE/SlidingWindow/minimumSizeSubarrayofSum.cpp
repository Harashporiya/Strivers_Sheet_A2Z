#include <bits/stdc++.h>
using namespace std;

int minimumSubarrayOfSum(vector<int>& nums, int n, int target) {
    int mini = INT_MAX;
    int left = 0, sum = 0;

    for (int right = 0; right < n; right++) {
        sum += nums[right];
        while (sum >= target) {  
            mini = min(mini, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return (mini == INT_MAX) ? 0 : mini;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    cout << minimumSubarrayOfSum(nums, n, target) << endl;
}
