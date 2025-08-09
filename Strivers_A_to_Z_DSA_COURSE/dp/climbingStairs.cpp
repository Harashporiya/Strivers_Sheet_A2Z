#include<bits/stdc++.h>
using namespace std;
int climbingStairs(int n){
    if(n==0 || n==1)return 1;
    // vector<int> dp(n+1,-1);
    // dp[0]=1;
    // dp[1]=1;

    // for(int i=2;i<n+1;i++){
    //     dp[i] = climbingStairs(i-1)+climbingStairs(i-2);
    // }
    // return dp[n];
   // return climbingStairs(n-1)+climbingStairs(n-2);

   int prev=1;
   int prev2=1;
   for(int i=2;i<n+1;i++){
    int cur = prev+prev2;
    prev2=prev;
    prev=cur;
   }
   return prev;
}
int main(){
    int n;
    cin>>n;
    cout<<climbingStairs(n);
}