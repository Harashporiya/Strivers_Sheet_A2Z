#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the largest submatrix with 1s after any number of column rearrangements
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Convert matrix to "heights" for each column
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        int ans = 0;

        // Step 2: For each row, sort the heights in descending order
        for(int i = 0; i < n; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for(int j = 0; j < m; j++) {
                // Calculate area = height * width (width = j+1 because sorted)
                ans = max(ans, matrix[i][j] * (j + 1));
            }
        }

        return ans;
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 1}
    };

    Solution sol;
    int result = sol.largestSubmatrix(matrix);
    cout << "Largest submatrix area: " << result << endl;

    return 0;
}