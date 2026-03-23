#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // -------------------- APPROACH 1: RECURSION --------------------
    pair<long long, long long> solveRec(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if (i >= n || j >= m) return {LLONG_MAX, LLONG_MIN};

        if (i == n - 1 && j == m - 1) {
            return {grid[i][j], grid[i][j]};
        }

        auto right = solveRec(i, j + 1, grid);
        auto down  = solveRec(i + 1, j, grid);

        long long maxi = LLONG_MIN, mini = LLONG_MAX;

        if (right.second != LLONG_MIN) {
            long long a = right.second * grid[i][j];
            long long b = right.first * grid[i][j];
            maxi = max(maxi, max(a, b));
            mini = min(mini, min(a, b));
        }

        if (down.second != LLONG_MIN) {
            long long a = down.second * grid[i][j];
            long long b = down.first * grid[i][j];
            maxi = max(maxi, max(a, b));
            mini = min(mini, min(a, b));
        }

        return {mini, maxi};
    }

    // -------------------- APPROACH 2: MEMOIZATION --------------------
    pair<long long, long long> solveMemo(int i, int j,
        vector<vector<int>>& grid,
        vector<vector<pair<long long,long long>>>& dp) {

        int n = grid.size(), m = grid[0].size();

        if (i >= n || j >= m) return {LLONG_MAX, LLONG_MIN};

        if (i == n - 1 && j == m - 1) {
            return {grid[i][j], grid[i][j]};
        }

        if (dp[i][j].first != LLONG_MAX) return dp[i][j];

        auto right = solveMemo(i, j + 1, grid, dp);
        auto down  = solveMemo(i + 1, j, grid, dp);

        long long maxi = LLONG_MIN, mini = LLONG_MAX;

        if (right.second != LLONG_MIN) {
            long long a = right.second * grid[i][j];
            long long b = right.first * grid[i][j];
            maxi = max(maxi, max(a, b));
            mini = min(mini, min(a, b));
        }

        if (down.second != LLONG_MIN) {
            long long a = down.second * grid[i][j];
            long long b = down.first * grid[i][j];
            maxi = max(maxi, max(a, b));
            mini = min(mini, min(a, b));
        }

        return dp[i][j] = {mini, maxi};
    }

    // -------------------- APPROACH 3: TABULATION --------------------
    int maxProductPathTab(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<long long>> maxi(n, vector<long long>(m));
        vector<vector<long long>> mini(n, vector<long long>(m));

        maxi[0][0] = mini[0][0] = grid[0][0];

        // first row
        for (int j = 1; j < m; j++) {
            maxi[0][j] = mini[0][j] = maxi[0][j-1] * grid[0][j];
        }

        // first col
        for (int i = 1; i < n; i++) {
            maxi[i][0] = mini[i][0] = maxi[i-1][0] * grid[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                long long a = maxi[i-1][j] * grid[i][j];
                long long b = mini[i-1][j] * grid[i][j];
                long long c = maxi[i][j-1] * grid[i][j];
                long long d = mini[i][j-1] * grid[i][j];

                maxi[i][j] = max({a,b,c,d});
                mini[i][j] = min({a,b,c,d});
            }
        }

        long long res = maxi[n-1][m-1];
        return (res >= 0) ? res % MOD : -1;
    }

    // -------------------- APPROACH 4: SPACE OPTIMIZED --------------------
    int maxProductPathSpaceOpt(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<long long> prevMax(m), prevMin(m);

        prevMax[0] = prevMin[0] = grid[0][0];

        for (int j = 1; j < m; j++) {
            prevMax[j] = prevMin[j] = prevMax[j-1] * grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            vector<long long> currMax(m), currMin(m);

            currMax[0] = currMin[0] = prevMax[0] * grid[i][0];

            for (int j = 1; j < m; j++) {
                long long a = prevMax[j] * grid[i][j];
                long long b = prevMin[j] * grid[i][j];
                long long c = currMax[j-1] * grid[i][j];
                long long d = currMin[j-1] * grid[i][j];

                currMax[j] = max({a,b,c,d});
                currMin[j] = min({a,b,c,d});
            }

            prevMax = currMax;
            prevMin = currMin;
        }

        long long res = prevMax[m-1];
        return (res >= 0) ? res % MOD : -1;
    }

    // -------------------- DRIVER FUNCTION --------------------
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(n,
            vector<pair<long long,long long>>(m, {LLONG_MAX, LLONG_MIN}));

        auto ans = solveMemo(0, 0, grid, dp);
        return (ans.second >= 0) ? ans.second % MOD : -1;
    }
};


// -------------------- MAIN FUNCTION --------------------
int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1, -2, 1},
        {1, -2, 1},
        {3, -4, 1}
    };

    cout << "Memoization Answer: " << obj.maxProductPath(grid) << endl;
    cout << "Tabulation Answer: " << obj.maxProductPathTab(grid) << endl;
    cout << "Space Optimized Answer: " << obj.maxProductPathSpaceOpt(grid) << endl;

    return 0;
}