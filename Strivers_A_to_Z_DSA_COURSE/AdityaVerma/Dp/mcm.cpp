
// Matrix chain multiplication
#include<bits/stdc++.h>
using namespace std;
int mcm(vector<int>&arr, int i,int j,vector<vector<int>>&dp){
    if(i>=j)return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    
    int mini=INT_MAX;
    
    for(int k=i;k<=j-1;k++){
        int tempans = mcm(arr,i,k,dp)+mcm(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
        
        mini=min(mini,tempans);
    }
    
    dp[i][j]=mini;
    
    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n,-1));
    cout<<mcm(arr,1,n-1,dp);
}