#include<bits/stdc++.h>
using namespace std;
bool jumpGame(vector<int>& arr){
    int n=arr.size();

    vector<bool> dp(n,false);
    dp[0]=true;

    for(int i=0;i<n;i++){
        if(dp[i]){
            for(int j=1;j<=arr[i]&&i+j<n;j++){
                dp[i+j]=true;
            }
        }
    }

    return dp[n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(jumpGame(arr)){
        cout<<"True";
    }else{
        cout<<"False";
    }
}