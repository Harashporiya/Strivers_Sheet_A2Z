#include<bits/stdc++.h>
using namespace std;
int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> checkPal(n,vector<bool>(n,false));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<=2 || checkPal[i+1][j-1])){
                    checkPal[i][j]=true;
                }
            }
        }
        
        vector<int> dp(n+1,0);
        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
          for(int j=i;j<s.size();j++){
            if(checkPal[i][j]){
            int cut =1+ dp[j+1];
                mini=min(mini,cut);
            }
     }
      dp[i]=mini;
        }
        return dp[0]-1;
}

int main(){
    string s;
    cin>>s;

    int ans= minCut(s);
    cout<<ans;
}