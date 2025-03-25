#include<bits/stdc++.h>
using namespace std;
int largestSubarrayWithZeroSum(vector<int>& a, int n){
    unordered_map<int,int> mpp;
    int sum=0;
    int maxi=0;
    for(int i=0;i<n;i++){
     sum+=a[i];
     if(sum==0){
        maxi=i+1;
     }else{
         if(mpp.find(sum)!=mpp.end()){
        maxi=max(maxi,i-mpp[sum]);
     }else{
        mpp[sum]=i;
     }
     }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res = largestSubarrayWithZeroSum(a,n);
    cout<<res;
}