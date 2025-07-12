#include<bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

       queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        q.push({0,{0,0}});

        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;

        int dr[] = {-1, -1, -1, 0, +1, +1, +1, 0};
        int dc[] = {-1,  0, +1, +1, +1,  0, -1, -1};
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }

        if(dist[n-1][m-1]==1e9)return -1;

        return dist[n-1][m-1]+1;


}
int main(){
    vector<vector<int>> grid={
        {0,0,0},{1,1,0},{1,1,0}
    };

    cout<<shortestPathBinaryMatrix(grid);
    cout<<endl;
}