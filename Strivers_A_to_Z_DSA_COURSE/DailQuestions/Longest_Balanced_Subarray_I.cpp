#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int,int> odd, even;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even[nums[j]]++;
                } else {
                    odd[nums[j]]++;
                }

                if (even.size() == odd.size()) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int ans = obj.longestBalanced(nums);

    cout << "Longest balanced subarray length: " << ans << endl;

    return 0;
}
