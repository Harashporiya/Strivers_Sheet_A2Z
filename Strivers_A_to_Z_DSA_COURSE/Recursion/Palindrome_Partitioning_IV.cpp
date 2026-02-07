#include<bits/stdc++.h>
using namespace std;

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
         vector<vector<int>> dp(n+1,vector<int>(3+1,false));
         dp[n][3]=true;
        // int c=INT_MAX;
         
         for (int i = n - 1; i >= 0; i--) {
        for (int p = 0; p < 3; p++) {
            for (int j = i; j < n; j++) {
                if (checkPal[i][j] && dp[j + 1][p + 1]) {
                    dp[i][p] = true;
                    break;
                }
            }
        }
    }
    return dp[0][0];
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