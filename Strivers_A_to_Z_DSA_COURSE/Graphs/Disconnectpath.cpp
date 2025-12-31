#include<bits/stdc++.h>
using namespace std;
int f(int n,int m ,int i,int j,vector<vector<int>>& grid){
  
    if(i==n-1&&j==m-1)return 1;

    if(i<0 || j<0 || n<=i || m<=j || grid[i][j]==0)return 0;

    int d=f(n,m,i+1,j,grid);
    int r=f(n,m,i,j+1,grid);

    return d+r;
}
bool isPossibleToCutPath(vector<vector<int>>& grid) {
  int n=grid.size();
  int m=grid[0].size();
 
  int ans=f(n,m,0,0,grid);
   
  cout<<ans<<endl;
  if(ans==1){
    return true;
  }
  return false;
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    if(isPossibleToCutPath(grid)){
        cout<<"True";
    }else
   cout<<"False";
}