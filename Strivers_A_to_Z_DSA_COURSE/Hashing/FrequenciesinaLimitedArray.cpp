#include<bits/stdc++.h>
using namespace std;
vector<int> frequenciesCountInLinmitedArray(vector<int> &a, int n){
    vector<int> ans(n,0);
    map<int, int> mpp;

    for(auto it:a){
       if(it>=1 && it<=n){
         mpp[it]++;
       }
    }

    for(int i=1;i<=n;i++){
        if(mpp.find(i)!=mpp.end()){
            ans[i-1] = mpp[i];
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

   vector<int> ans = frequenciesCountInLinmitedArray(a,n);
    for(auto it:ans){
        cout<<it<<" ";
    }
}