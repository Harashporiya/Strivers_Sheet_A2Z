#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &a, int n, int k){
    int low=0;
    int high=n-1;
    int ans = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
    if(a[mid]<=k){
            ans = a[mid];
           low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
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