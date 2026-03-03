#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int ind, vector<int>& arr, int target) {
        if (target == 0) return true;
        if (ind == 0) return (arr[0] == target);

        bool notTake = solve(ind - 1, arr, target);
        bool take = false;

        if (target >= arr[ind])
            take = solve(ind - 1, arr, target - arr[ind]);

        return take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return solve(n - 1, arr, sum);
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