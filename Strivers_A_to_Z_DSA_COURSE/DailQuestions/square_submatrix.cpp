#include <bits/stdc++.h>
using namespace std;

// 🐢 Brute Force Approach (uses extra space)
vector<vector<int>> bruteForce(vector<vector<int>> grid, int x, int y, int k) {
    vector<vector<int>> subMat;

    // Step 1: Extract submatrix
    for (int i = x; i < x + k; i++) {
        vector<int> row;
        for (int j = y; j < y + k; j++) {
            row.push_back(grid[i][j]);
        }
        subMat.push_back(row);
    }

    // Step 2: Reverse rows
    reverse(subMat.begin(), subMat.end());

    // Step 3: Put back
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            grid[x + i][y + j] = subMat[i][j];
        }
    }

    return grid;
}

// ⚡ Optimal Approach (in-place swapping)
vector<vector<int>> optimal(vector<vector<int>> grid, int x, int y, int k) {

    for (int i = 0; i < k / 2; i++) {
        for (int j = 0; j < k; j++) {
            swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
        }
    }

    return grid;
}

// 🖨️ Utility function to print matrix
void printGrid(vector<vector<int>> &grid) {
    for (auto &row : grid) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "------------------" << endl;
}

// 🚀 Main function (no user input)
int main() {

    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int x = 1, y = 0, k = 3;

    cout << "Original Grid:\n";
    printGrid(grid);

    // Brute Force
    vector<vector<int>> bruteAns = bruteForce(grid, x, y, k);
    cout << "After Brute Force:\n";
    printGrid(bruteAns);

    // Optimal
    vector<vector<int>> optimalAns = optimal(grid, x, y, k);
    cout << "After Optimal:\n";
    printGrid(optimalAns);

    return 0;
}