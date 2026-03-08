#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<long long> product(n);
        vector<long long> sum(n);

        sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + nums[i];
        }

        product[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            if(product[i+1] > LLONG_MAX / nums[i])
                product[i] = LLONG_MAX;
            else
                product[i] = product[i+1] * nums[i];
        }

        for(int i = 0; i < n; i++){
            long long leftSum = (i == 0) ? 0 : sum[i-1];
            long long rightProduct = (i == n-1) ? 1 : product[i+1];

            if(leftSum == rightProduct) return i;
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 8, 2, 2, 5};

    int result = obj.smallestBalancedIndex(nums);

    cout << "Smallest Balanced Index: " << result << endl;

    return 0;
}