#include<bits/stdc++.h>
using namespace std;
int frogJump(vector<int>&arr,int k,int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
      int mini=INT_MAX;
      dp[0]=0;
    for(int i=1;i<=k;i++){
        int jump = frogJump(arr,k,n-i,dp)+abs(arr[n]-arr[n-i]);
        mini=min(mini,jump);
    }

    return dp[n] = mini;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;
    vector<int> dp(n+1,-1);
    cout<<frogJump(arr,k,n-1,dp);
}