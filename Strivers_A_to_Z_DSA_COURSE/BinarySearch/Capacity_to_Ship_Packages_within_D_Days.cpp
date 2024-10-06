#include<bits/stdc++.h>
using namespace std;
int maxElements(int a[], int n){
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi, a[i]);
    }
    return maxi;
}
int sumOfArrayElements(int a[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}
int findDays(int a[], int mid, int n){
    int days=1; int load=0;
    for(int i=0;i<n;i++){
        if(a[i]+load>mid){
            days+=1;
            load = a[i];
        }else{
            load +=a[i];
        }
    }
    return days;
  
}
int capacity(int a[], int n, int d){
   int low = maxElements(a,n);
   int high = sumOfArrayElements(a,n);
   while(low<=high){
    int mid = low+(high-low)/2;
    if(findDays(a,mid,n)<=d){
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
    int d;
    cin>>d;
    int ans = capacity(a,n,d);
    cout<<ans;
}