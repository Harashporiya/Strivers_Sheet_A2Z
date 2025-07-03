#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}

int numIsland(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !vis[i][j]) {
                cnt++;
                bfs(i, j, grid, vis);
            }
        }
    }
    return cnt;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    cout << numIsland(grid) << endl;
    return 0;
}