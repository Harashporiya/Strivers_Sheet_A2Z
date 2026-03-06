#include <bits/stdc++.h>
using namespace std;

// ===================== LARGEST RECTANGLE IN HISTOGRAM =====================
int largestRectangleArea(vector<int>& h) {
    int n = h.size();
    stack<int> st;
    int maxi = 0;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || h[st.top()] >= h[i])) {
            int height = h[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxi = max(maxi, width * height);
        }
        st.push(i);
    }

    return maxi;
}

// ===================== MAXIMAL RECTANGLE IN BINARY MATRIX =====================
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> height(m, 0);
    int maxarea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') height[j]++;
            else height[j] = 0;
        }
        maxarea = max(maxarea, largestRectangleArea(height));
    }

    return maxarea;
}

// ===================== MAIN FUNCTION =====================
int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int maxRectArea = maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << maxRectArea << endl;

    return 0;
}