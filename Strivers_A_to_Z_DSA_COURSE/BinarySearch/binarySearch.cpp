#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &a, int n, int k){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(a[mid]==k){
          return a[mid];
        }else if(a[mid]<k){
           low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans = binarySearch(a,n,k);
    cout<<ans;
}