#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int st,int ed){
        while(st<=ed){
            if(s[st++]!=s[ed--])return false;
        }
        return true;
    }
   int f(int ind,string s,vector<int>&dp){
    if(ind==s.size()){
       return 0;
    }
    if(dp[ind]!=-1)return dp[ind];
    int mini=INT_MAX;
     for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i)){
           int cut =1+ f(i+1,s,dp);
            mini=min(mini,cut);
        }
     }
     return dp[ind]=mini;
}
int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return f(0,s,dp)-1;
}

int main(){
    string s;
    cin>>s;

    int ans= minCut(s);
    cout<<ans;
}