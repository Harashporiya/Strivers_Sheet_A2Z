#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int f(int n, int x, int y, int z, vector<int>& dp) {
        if (n == 0) return 0;
        if (n < 0) return INT_MIN;

        if (dp[n] != -1) return dp[n];

        int a = f(n - x, x, y, z, dp);
        int b = f(n - y, x, y, z, dp);
        int c = f(n - z, x, y, z, dp);

        int best = max({a, b, c});
        if (best == INT_MIN)
            return dp[n] = INT_MIN;

        return dp[n] = 1 + best;
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);
        int ans = f(n, x, y, z, dp);
        return (ans < 0) ? 0 : ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y, z;
        cin >> n >> x >> y >> z;

        Solution obj;
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }
    return 0;
}
