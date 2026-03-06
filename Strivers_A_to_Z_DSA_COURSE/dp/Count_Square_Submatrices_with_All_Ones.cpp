#include <bits/stdc++.h>
using namespace std;

// ===================== BRUTE FORCE =====================
int countSquaresBruteForce(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                int size = 1;
                bool flag = true;
                while (i + size - 1 < n && j + size - 1 < m && flag) {
                    for (int x = i; x <= i + size - 1; x++) {
                        if (matrix[x][j + size - 1] == 0) {
                            flag = false;
                            break;
                        }
                    }
                    for (int y = j; y <= j + size - 1; y++) {
                        if (matrix[i + size - 1][y] == 0) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) ans++;
                    size++;
                }
            }
        }
    }
    return ans;
}

// ===================== RECURSIVE WITH MEMOIZATION =====================
int countSquaresRecHelper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (i >= n || j >= m || matrix[i][j] == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int down = countSquaresRecHelper(i + 1, j, matrix, dp);
    int right = countSquaresRecHelper(i, j + 1, matrix, dp);
    int diag = countSquaresRecHelper(i + 1, j + 1, matrix, dp);

    return dp[i][j] = 1 + min({down, right, diag});
}

int countSquaresMemoization(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 1)
                ans += countSquaresRecHelper(i, j, matrix, dp);

    return ans;
}

// ===================== BOTTOM-UP DP =====================
int countSquaresDP(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                ans += dp[i][j];
            }
        }
    }
    return ans;
}

// ===================== MAIN FUNCTION =====================
int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    cout << "Brute Force: " << countSquaresBruteForce(matrix) << endl;
    cout << "Memoization (Top-Down DP): " << countSquaresMemoization(matrix) << endl;
    cout << "Bottom-Up DP: " << countSquaresDP(matrix) << endl;

    return 0;
}