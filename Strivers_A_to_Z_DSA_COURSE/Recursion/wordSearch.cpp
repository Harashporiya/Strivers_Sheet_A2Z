#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int r, int c, int ind, vector<vector<int>>& vis, vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        if (ind == word.size()) {
            return true;
        }

        vis[r][c] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == word[ind] && vis[nr][nc] == 0) {
                if (dfs(nr, nc, ind + 1, vis, board, word)) {
                    return true;
                }
            }
        }

        vis[r][c] = 0; // Unmark the cell for the next DFS search
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 1, vis, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    cout << obj.exist(board, word) << endl;

    return 0;
}
