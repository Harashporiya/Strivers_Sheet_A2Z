#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count all strictly increasing paths in a grid.
Approach:
1. Use DFS with memoization.
2. For each cell, explore 4 directions (up, right, down, left).
3. Only move to a cell if its value is greater than the current cell.
4. Use a dp table to store results and avoid recomputation.
5. Sum all paths starting from each cell, modulo 1e9+7.
*/

class Solution {
public:
    const int MOD = 1e9+7;

    // DFS function to count increasing paths starting from (r, c)
    int dfs(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Directions: up, right, down, left
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        // If already computed, return the stored value
        if (dp[r][c] != -1) return dp[r][c];

        int sum = 1; // Path of length 1 (the cell itself)

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check bounds and strictly increasing condition
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[r][c] < grid[nr][nc]) {
                sum = (sum + dfs(nr, nc, dp, grid)) % MOD;
            }
        }

        return dp[r][c] = sum;
    }

    // Main function to count all increasing paths in the grid
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum = (sum + dfs(i, j, dp, grid)) % MOD;
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    // Example grid
    vector<vector<int>> grid = {
        {1, 2},
        {3, 4}
    };

    int result = sol.countPaths(grid);
    cout << "Total strictly increasing paths: " << result << endl;

    return 0;
}