#include<bits/stdc++.h>
using namespace std;
int maxElements(int a[], int n){
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi, a[i]);
    }
    return maxi;
}
int answere(int a[], int n, int t, int mid){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double) a[i]/ (double) mid);
    }
    return sum;
}
int findSmallestDivisor(int a[], int n, int t){
    int low=1;
    int high =maxElements(a, n);
   
    while(low<=high){
        int mid = low+(high-low)/2;
          if(answere(a,n,t,mid)<=t){
            high=mid-1;
          
          }else{
           low=mid+1;
          }
    }
    return low;
}
int main(){
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int t;
   cin>>t;
   int ans = findSmallestDivisor(a,n,t);
   cout<<ans;


}