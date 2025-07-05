#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> zeroOneMat(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();

    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({i,j});
            }else{
               mat[i][j]=-1;
            }
        }

    }

    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};

    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol = col+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==-1){
                mat[nrow][ncol] =mat[row][col]+1;
                q.push({nrow,ncol});
            }
        }
    }
    return mat;
}
int main(){

    vector<vector<int>> mat={
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    vector<vector<int>> ans = zeroOneMat(mat);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}