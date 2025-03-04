#include<bits/stdc++.h>
using namespace std;
int largestSubarrayOfK(vector<int>& a, int n, int k){
  int maxi = 0;
  int i=0,j=0;
  int sum = 0;
  while(j<n){
     sum += a[j]; 
         while(sum>k && i<=j){
           sum -=a[i];
           i++;
         }
     
      if(sum==k){
        maxi = max(maxi,j-i+1);
     }
     j++;
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

    int k;
    cin>>k;

    cout<<largestSubarrayOfK(a,n,k);
}