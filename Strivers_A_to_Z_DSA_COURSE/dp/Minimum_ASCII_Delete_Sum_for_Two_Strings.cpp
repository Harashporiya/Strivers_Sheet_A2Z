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
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(0,0,s1,s2,dp);
}
int main(){
    string s1="sea";
    string s2="eat";

    cout<<minimumDeleteSum(s1,s2);
}