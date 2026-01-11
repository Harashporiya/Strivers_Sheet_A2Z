#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int maxi = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || h[st.top()] >= h[i])) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxi = max(maxi, height * width);
            }
            if (i < n) st.push(i);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            maxarea = max(maxarea, largestRectangleArea(height));
        }
        return maxarea;
    }
};

int main() {
    Solution sol;

    // Sample input matrix
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << "Maximal Rectangle Area: "
         << sol.maximalRectangle(matrix) << endl;

    return 0;
}
