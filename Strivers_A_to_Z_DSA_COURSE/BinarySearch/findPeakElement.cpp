#include<bits/stdc++.h>
using namespace std;
int findPeakElements(vector<int> &a, int n){
    if(n==1) return a[0];
   int low=0;
   int high=n-1;
   while(low<=high){
    int mid = low+(high-low)/2;

    if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
        return a[mid];
    }

    if( a[mid-1]<a[mid] && a[mid]<a[mid+1]){
        low=mid+1;
    }else if(a[mid]>a[mid] && a[mid]>a[mid+1]){
        high=mid-1;
    }
   }
   return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans = findPeakElements(a,n);
    cout<<ans;
}