#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>, int>> q;
        int cntFresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }

                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int tm=0;
        int cnt=0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm=max(tm,t);

            for(int i=0;i<4;i++){
                int nrow = row+delRow[i];
                int ncol = col+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }

        if(cnt!=cntFresh) return -1;

        return tm;
}

int main(){
    vector<vector<int>> grid = {
        {2,1,1},{0,1,1},{1,0,1}
    };

    cout<<orangesRotting(grid)<<endl;
}