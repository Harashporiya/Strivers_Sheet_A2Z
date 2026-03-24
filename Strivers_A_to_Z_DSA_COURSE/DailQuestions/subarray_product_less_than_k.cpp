#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Edge case
        if (k <= 1) return 0;

        int n = nums.size();
        int left = 0;
        long long product = 1;
        int count = 0;

        // Sliding window
        for (int right = 0; right < n; right++) {
            product *= nums[right];

            // Shrink window if product >= k
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            // Count valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }
};

int main() {
    // Hardcoded test case (no user input)
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    Solution sol;

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    cout << "K = " << k << endl;

    int result = sol.numSubarrayProductLessThanK(nums, k);

    cout << "\nNumber of subarrays with product < K: " << result << endl;

    return 0;
}