//Longest Palindromic Subsequence
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1;
    cin>>s1;
    string s2=s1;
    reverse(s2.begin(),s2.end());
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