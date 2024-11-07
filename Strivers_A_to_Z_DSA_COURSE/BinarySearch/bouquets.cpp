#include<bits/stdc++.h>
using namespace std;
bool isValid(int a[],int n, int m, int k, int mid ){
    int count=0;
    int noFB=0;
    for(int i=0;i<n;i++){
        if(a[i]<=mid){
            count++;
        }else{
            noFB+=(count/k);
            count=0;
        }
    }
    noFB+=(count/k);
    return noFB>=m;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int required_bouquets,requires_flower;
    cin>>required_bouquets>>requires_flower;
    if(required_bouquets*requires_flower>n){
        cout<<"-1";
    }
    int maxi=INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        maxi=max(maxi, a[i]);
        mini=min(mini, a[i]);
    }
    int low=mini;
    int high=maxi;
    int ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(isValid(a,n,required_bouquets,requires_flower,mid)){
            ans = mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans;

    return 0;
}