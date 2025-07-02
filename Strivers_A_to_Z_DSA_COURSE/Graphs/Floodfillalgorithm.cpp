#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>> &ans,
         int delRow[], int delCol[], int iniColor, int newColor) {
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, image, ans, delRow, delCol, iniColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, image, ans, delRow, delCol, iniColor, color);
    return ans;
}

int main() {
    int sr = 1;
    int sc = 1;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int color = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, color);

    
    for (auto row : result) {
        for (auto pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
