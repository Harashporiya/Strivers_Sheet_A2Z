#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int k){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        queue<pair<long long,pair<int,int>>> q;
        q.push({grid[r][c],{r,c}});

        long long sum=0;

        while(!q.empty()){
            int rc=q.front().second.first;
            int cc=q.front().second.second;
            long long val=q.front().first;
            q.pop();

            sum+=val;

            for(int i=0;i<4;i++){
                int nr=rc+dr[i];
                int nc=cc+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=0 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({grid[nr][nc],{nr,nc}});
                }
            }
        }

        return (sum % k == 0);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    if(dfs(i,j,grid,vis,k)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int k;
    cin>>k;

    Solution obj;
    cout<<obj.countIslands(grid,k)<<endl;

    return 0;
}
