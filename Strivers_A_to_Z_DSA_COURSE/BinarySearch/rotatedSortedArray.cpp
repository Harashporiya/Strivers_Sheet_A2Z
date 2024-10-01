#include<bits/stdc++.h>
using namespace std;
int rotatedSortedArray(vector<int> &a, int n, int k){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(a[mid]==k){
          return mid;
        }else if(a[low]<=a[mid]){
            if(a[low]<=k && k<=a[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(a[mid]<=k && k<=a[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
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

    int ans = rotatedSortedArray(a,n,k);
    cout<<ans;
}