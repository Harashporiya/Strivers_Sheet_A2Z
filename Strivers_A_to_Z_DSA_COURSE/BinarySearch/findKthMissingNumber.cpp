#include<bits/stdc++.h>
using namespace std;
int findKthMissingNumber(int a[], int n, int k){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid =(low+high)/2;
        int missingNumber = a[mid] - (mid+1);
        if(missingNumber<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high+k+1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    // for(int i=0;i<n;i++){
    //     if(a[i]<=k){
    //         k++;
    //     }else{
    //         break;
    //     }
    // }
    // cout<<k;

    int ans = findKthMissingNumber(a,n,k);
    cout<<ans;
}