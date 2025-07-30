#include<bits/stdc++.h>
using namespace std;
vector<int> coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,0);

        dp[0]=1;

        for(int coin:coins){
            for(int j=coin;j<=amount;j++){
                dp[j] += dp[j-coin];
            }
        }

        return dp;
}
int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int amount;
    cin>>amount;

    vector<int> ans =coinChange(coins,amount);
    for(auto it:ans){
        cout<<it<<" ";
    }
}