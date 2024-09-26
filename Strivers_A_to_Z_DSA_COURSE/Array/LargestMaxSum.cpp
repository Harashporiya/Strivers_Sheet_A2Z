#include<bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &a, int n){
    unordered_map<int, int> mpp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==0){
            maxi=i+1;
        }else{
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi, i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int res = maxLen(a,n);
    cout<<res;
}