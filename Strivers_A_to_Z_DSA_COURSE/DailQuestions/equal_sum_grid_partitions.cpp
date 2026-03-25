#include<bits/stdc++.h>
using namespace std;

bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       
        long long t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                t+=grid[i][j];
            }
        }

        if(t%2==1)return false;

        t=t/2;

        long long s=0;

        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                s+=grid[i][j];

                if(s==t){
                    return true;
                }
            }
        }
        s=0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                s+=grid[j][i];

                if(s==t){
                    return true;
                }
            }
        }

        return false;

}
int main(){
    vector<vector<int>> grid={
        {1,4},
        {2,3}
    };

    if(canPartitionGrid(grid)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}