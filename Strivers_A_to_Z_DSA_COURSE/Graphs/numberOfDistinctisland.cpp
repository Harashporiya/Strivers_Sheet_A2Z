#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>>& grid,vector<pair<int,int>>& vec,vector<vector<int>>& vis,int row0, int col0){
  vis[row][col]=1;
  vec.push_back({row-row0,col-col0});
  int n=grid.size();
    int m=grid[0].size();

    int delRow[]={-1,0,+1,0};
    int delCol[]={0,+1,0,-1};

    for(int i=0;i<4;i++){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
            dfs(nrow,ncol,grid,vec,vis,row0,col0);
        }
    }

}
int countDistinctIslands(vector<vector<int>>& grid) {
  
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));

    set<vector<pair<int,int>>> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==1){
                vector<pair<int,int>> vec;
                dfs(i,j,grid,vec,vis,i,j);
                s.insert(vec);
            }
        }
    }
  return s.size();
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1}};

    cout<<countDistinctIslands(grid)<<endl;

}