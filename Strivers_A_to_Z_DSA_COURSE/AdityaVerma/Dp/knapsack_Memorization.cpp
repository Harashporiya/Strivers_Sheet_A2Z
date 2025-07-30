#include<bits/stdc++.h>
using namespace std;
int knapSack(vector<int>&wt,vector<int>&val,int w,int n, vector<vector<int>>&dp){
    if(w==0 || n==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    if(wt[n-1]<=w){
        int include = val[n-1] + knapSack(wt, val, w - wt[n-1], n - 1,dp);
        int exclude = knapSack(wt, val, w, n - 1,dp);
        return dp[n][w] = max(include, exclude);
    }else if(wt[n-1]>w){
        return dp[n][w] = knapSack(wt,val,w,n-1,dp);
    }
    return 0;
}
int main(){
    vector<int> wt={4,5,1};
    vector<int> val={1,2,3};
    int n=3;
    int w=4;
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));

    cout<<knapSack(wt,val,w,3,dp);
}