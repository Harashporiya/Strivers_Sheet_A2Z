#include<bits/stdc++.h>
using namespace std;
int binarySubArray(vector<int>& a, int n, int k){
  int maxi = 0;
  int i=0,j=0;
  int sum = 0;
  int ans =0;
  while(j<n){
    sum += a[j];

    while(sum>k){
        sum -= a[i];
        i++;
    }
    ans += j-i+1;
    j++;
  }

  return ans;

}
int mostCountk(vector<int>& a, int n, int k){
  return binarySubArray(a,n,k) - binarySubArray(a,n,k-1);
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

    cout<<mostCountk(a,n,k);
}