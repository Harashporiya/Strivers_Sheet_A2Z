#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& maze, vector<string>& ans, vector<vector<int>>& vis, string path) {
        int n = maze.size();
        int m = maze[0].size();
        
        if (r == n - 1 && c == m - 1) {
            ans.push_back(path);
            return;
        }
        
        int dr[] = {+1, 0, 0, -1};
        int dc[] = {0, -1, +1, 0};
        char move[] = {'D', 'L', 'R', 'U'};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == 1 && vis[nr][nc] == 0) {
                vis[r][c] = 1;
                dfs(nr, nc, maze, ans, vis, path + move[i]);
                vis[r][c] = 0;
            }
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        int m = maze[0].size();
        
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        if (maze[0][0] == 1) {
            dfs(0, 0, maze, ans, vis, "");
        }
        
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);
    
    if (paths.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& path : paths) {
            cout << path << endl;
        }
    }
    
    return 0;
}
