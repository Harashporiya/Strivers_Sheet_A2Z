#include<bits/stdc++.h>
using namespace std;
int numberOfSubarray(vector<int> &a, int n, int k){
    int xr=0;
    map<int, int> mpp;
    mpp[xr]++;
    int count=0;
    for(int i=0;i<n;i++){
        xr = xr ^ a[i];

        int x = xr ^ k;
        count+=mpp[x];
        mpp[xr]++;
    }
    return count;
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = numberOfSubarray(a,n,k);
    cout<<ans;
}