#include<bits/stdc++.h>
using namespace std;
vector<int> majority(int a[], int n){
    map<int, int> mpp;
    vector<int> ans;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
        if(mpp[a[i]] == (n/3)+1){
          ans.push_back(a[i]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> ans = majority(a,n);
   for(auto it:ans){
    cout<<it<<" ";
   }

}