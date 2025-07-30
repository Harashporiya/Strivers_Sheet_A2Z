#include<bits/stdc++.h>
using namespace std;
// int lcs(string s1, string s2, int n, int m, vector<vector<int>>&dp){
//     if(n==0 || m==0){
//         return 0;
//     }
//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }

//     if(s1[n-1]==s2[m-1]){
//         return dp[n][m] =  1+lcs(s1,s2,n-1,m-1,dp);
//     }else{
//         return dp[n][m] = max(lcs(s1,s2,n-1,m,dp),lcs(s1,s2,n,m-1,dp));
//     }
// }
int main(){
    // string s1,s2;
    // cin>>s1>>s2;
    //  vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    // cout<<lcs(s1,s2,s1.length(),s2.length(),dp);

    string s1,s2;
    cin>>s1>>s2;
     vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
     int n=s1.length();
     int m=s2.length();
     for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
          if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
          }else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
        }
     }
    cout<<dp[n][m];
}