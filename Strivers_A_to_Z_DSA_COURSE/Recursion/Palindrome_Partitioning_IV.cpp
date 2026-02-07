#include<bits/stdc++.h>
using namespace std;

bool f(int ind,string s,int p,vector<vector<bool>> &checkPal,vector<vector<int>>&dp){
    if(ind==s.size() && p==3){
        
        return true;
    }
    if (ind == s.size() || p == 3) return false;

    if(dp[ind][p]!=-1){
        return dp[ind][p];
    }
     for(int i=ind;i<s.size();i++){
        if(checkPal[ind][i]){
            if(f(i+1,s,p+1,checkPal,dp)==true){
                return dp[ind][p]=true;
            }
        }
     }
     return dp[ind][p]=false;
}
bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<bool>> checkPal(n,vector<bool>(n,false));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<=2 || checkPal[i+1][j-1])){
                    checkPal[i][j]=true;
                }
            }
        }
         int p=0;
         vector<vector<int>> dp(n,vector<int>(3+1,-1));
        // int c=INT_MAX;
        if(f(0,s,p,checkPal,dp)){
            return true;
        }
        return false;
}

int main(){
    string s;
    cin>>s;

    if(checkPartitioning(s)){
        cout<<"TRUE";
    }else{
        cout<<"FALSE";
    }
}