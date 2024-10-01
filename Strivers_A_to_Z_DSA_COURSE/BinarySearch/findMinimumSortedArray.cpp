#include<bits/stdc++.h>
using namespace std;
int findMinimumRotatedSortedArray(vector<int> &a, int n){
    int low=0;
    int high=n-1;
    int ans =a[0];
    while(low<=high){
        int mid = low+(high-low)/2;
       if(a[low]<=a[high]){
        ans=min(ans,a[low]);
        break;
       }
       if(a[low]<=a[mid]){
        ans=min(ans,a[low]);
        low=mid+1;
       }else{
        ans=min(ans,a[mid]);
        high=mid-1;
       }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans = findMinimumRotatedSortedArray(a,n);
    cout<<ans;
}