#include<bits/stdc++.h>
using namespace std;
int binarySearch(int n){
    int low=1;
    int high=n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(mid*mid<=n){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}
int main(){
    int n;
    cin>>n;

    int ans = binarySearch(n);
    cout<<ans;
}