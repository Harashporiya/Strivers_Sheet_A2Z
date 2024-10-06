#include<iostream>
using namespace std;
int bitonicArray(int a[], int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
            return a[mid];
        }
        if(a[mid]<a[mid+1]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = bitonicArray(a,n);
    cout<<ans;
}