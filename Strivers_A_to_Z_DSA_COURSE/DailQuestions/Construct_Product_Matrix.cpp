#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int p = n * m;

        vector<int> nums;

        // Step 1: Flatten grid and take modulo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums.push_back(grid[i][j] % 12345);
            }
        }

        // Step 2: Prefix and suffix product arrays
        vector<int> prefix(p, 1), suffix(p, 1);

        for (int i = 1; i < p; i++) {
            prefix[i] = (prefix[i - 1] * nums[i - 1]) % 12345;
        }

        for (int i = p - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * nums[i + 1]) % 12345;
        }

        // Step 3: Build result matrix
        for (int i = 0; i < p; i++) {
            int val = (prefix[i] * suffix[i]) % 12345;
            grid[i / m][i % m] = val;
        }

        return grid;
    }
};

// Utility function to print matrix
void printMatrix(vector<vector<int>>& grid) {
    for (auto& row : grid) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Hardcoded test case (no user input)
    vector<vector<int>> grid = {
        {1, 2},
        {3, 4}
    };

    Solution sol;

    cout << "Original Matrix:\n";
    printMatrix(grid);

    vector<vector<int>> result = sol.constructProductMatrix(grid);

    cout << "\nProduct Matrix:\n";
    printMatrix(result);

    return 0;
}