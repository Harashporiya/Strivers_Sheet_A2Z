#include<bits/stdc++.h>
using namespace std;
vector<int> constructTransformedArray(vector<int>&v){
    int n=v.size();
    vector<int> ans(n);

    for(int i=0;i<n;i++){
       if(v[i]==0){
        ans[i]=0;
       }else{
        int m=v[i]%n;
        int l=(i+m+n)%n;
        ans[i]=v[l];
       }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans=constructTransformedArray(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
}