#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        vector<int> x(m, 0), y(m, 0);

        for (int i = 0; i < n; i++) {
            int rx = 0, ry = 0;

            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    rx++;
                } else if (grid[i][j] == 'Y') {
                    ry++;
                }

                x[j] += rx;
                y[j] += ry;

                if (x[j] == y[j] && x[j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Hardcoded grid (no user input)
    vector<vector<char>> grid = {
        {'X', 'Y', 'X'},
        {'Y', 'X', 'Y'},
        {'X', 'X', 'Y'}
    };

    int result = sol.numberOfSubmatrices(grid);

    cout << "Number of valid submatrices: " << result << endl;

    return 0;
}