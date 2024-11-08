#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(int arr1[], int n, int arr2[], int m){
    vector<int> res;
    int i=0;int j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            res.push_back(arr1[i++]);
        }else{
            res.push_back(arr2[j++]);
        }
    }
    while(i<n){
         res.push_back(arr1[i++]);
    }
    while(j<m){
         res.push_back(arr2[j++]);
    }
    int n1 = n+m;
    if(n1%2==1){
        return (double) res[n1/2];
    }

    return ((double) res[(n1/2)] + (double) res[(n1/2)-1])/2.0;
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