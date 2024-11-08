#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(int arr1[], int n, int arr2[], int m){
    // vector<int> res;
    // int i=0;int j=0;
    // while(i<n && j<m){
    //     if(arr1[i]<arr2[j]){
    //         res.push_back(arr1[i++]);
    //     }else{
    //         res.push_back(arr2[j++]);
    //     }
    // }
    // while(i<n){
    //      res.push_back(arr1[i++]);
    // }
    // while(j<m){
    //      res.push_back(arr2[j++]);
    // }
    // int n1 = n+m;
    // if(n1%2==1){
    //     return (double) res[n1/2];
    // }

    // return ((double) res[(n1/2)] + (double) res[(n1/2)-1])/2.0;
    if(n>m){
        return findMedianSortedArrays(arr2,m,arr1,n);
    }
    int low=0;
    int high=n;
    int n1 = n+m;
    int left=(n+m+1)/2;
    while(low<=high){
        int mid1 = (low+high)>>1;
        int mid2 = left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1 < n) r1 = arr1[mid1];
        if(mid2<m) r2 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2=arr2[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n1%2==1){
                return (double)max(l1,l2);
            }
            return ((double) max(l1,l2)+(double)min(r1,r2))/2.0;
        }else if(l1>l2){
            high=mid1-1;
        }else{
            low=mid1+1;
        }
    }
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
  double res =  findMedianSortedArrays(arr1,n,arr2,m);
  cout<<res;
}