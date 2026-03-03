bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<bool> prev(sum + 1, false);

    prev[0] = true;
    if (arr[0] <= sum)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        vector<bool> curr(sum + 1, false);
        curr[0] = true;

        for (int target = 1; target <= sum; target++) {
            bool notTake = prev[target];
            bool take = false;

            if (target >= arr[i])
                take = prev[target - arr[i]];

            curr[target] = take || notTake;
        }
        prev = curr;
    }

    return prev[sum];
}