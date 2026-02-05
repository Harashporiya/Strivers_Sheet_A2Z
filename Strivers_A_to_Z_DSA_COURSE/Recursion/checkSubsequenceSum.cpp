#include<bits/stdc++.h>
using namespace std;
bool f(int i,int n,vector<int>&arr,int k,int sum){
    if(i==n){
        return 0;
    }
  if(sum==k)return 1;
  if(sum>k)return 0;

  sum+=arr[i];
  int take =f(i+1,n,arr,k,sum);
  sum-=arr[i];
 int notTake = f(i+1,n,arr,k,sum);

return take | notTake;
}
bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    if(f(0,n,arr,k,0)){
        return 1;
    }    
    return 0;
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
    if(checkSubsequenceSum(n,arr,k)){
        cout<<"TRUE";
    }else{
        cout<<"FALSE";
    }
}