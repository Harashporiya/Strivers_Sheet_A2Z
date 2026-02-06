#include<bits/stdc++.h>
using namespace std;
int minRemoval(vector<int>&nums,int k){
    int n=nums.size();
    int maxi=1;
    sort(nums.begin(),nums.end());

    int l=0,r=0;

    while(r<n){
        if(nums[r]<=nums[l]*k){
            maxi=max(maxi,r-l+1);
        }else{
            l++;
        }
        r++;
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<minRemoval(arr,k);
}