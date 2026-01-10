#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,string s1,string s2, vector<vector<int>>& dp){
    int n=s1.size();
    int m=s2.size();

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(i==n){
        int s=0;
        for(int k=j;k<m;k++){
            s+=s2[k];
        }
        return dp[i][j]=s;
    }

    if(j==m){
        int s=0;
        for(int k=i;k<n;k++){
            s+=s1[k];
        }
        return dp[i][j]=s;
    }

    if(s1[i]==s2[j]){
        return f(i+1,j+1,s1,s2,dp);
    }

    int d1=s1[i]+f(i+1,j,s1,s2,dp);
    int d2=s2[j]+f(i,j+1,s1,s2,dp);

    return dp[i][j]=min(d1,d2);
}
int minimumDeleteSum(string s1,string s2){
     int n=s1.size();
    int m=s2.size();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> cur(m+1,0),prev(m+1,0);
    // for(int i=1;i<=n;i++){
    //  cur[0]=s1[i-1]+prev[0];
    // }

    for(int i=1;i<=m;i++){
     prev[i]=s2[i-1]+prev[i-1];
    }

    for(int i=1;i<=n;i++){
        cur[0] = prev[0] + s1[i-1];
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                 cur[j]=prev[j-1];
            }else{
                int d1=s1[i-1]+prev[j];
                int d2=s2[j-1]+cur[j-1];

                cur[j]=min(d1,d2);
            }
        }
        prev=cur;
    }

    return prev[m];
}
int main(){
    string s1="sea";
    string s2="eat";

    cout<<minimumDeleteSum(s1,s2);
}