#include<bits/stdc++.h>
using namespace std;
int frogJump(vector<int>&arr,int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
   int jumpFirst = frogJump(arr,n-1,dp)+abs(arr[n]-arr[n-1]);
   int jumpSecond;
   if(n>1){
    jumpSecond=frogJump(arr,n-2,dp)+abs(arr[n]-arr[n-2]);
   }
     return dp[n]=min(jumpSecond,jumpFirst);
   
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // vector<int> dp(n+1,-1);
    // cout<<frogJump(arr,n-1,dp);

    int prev=0;
    int prev2=0;

    for(int i=1;i<n;i++){
        int jumpFirst = prev+abs(arr[i]-arr[i-1]);
   int jumpSecond=INT_MAX;
   if(i>1){
    jumpSecond=prev2+abs(arr[i]-arr[i-2]);

   }

   int cur=min(jumpSecond,jumpFirst);
   prev2=prev;
   prev=cur;
    }
    cout<<prev;
}