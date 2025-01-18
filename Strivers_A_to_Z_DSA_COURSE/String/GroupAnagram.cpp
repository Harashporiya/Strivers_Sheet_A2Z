#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;

       for(auto word:strs){
        string x = word;
        sort(x.begin(), x.end());
        mpp[x].push_back(word);
       }

       for(auto it:mpp){
         ans.push_back(it.second);
       }

       return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<string>> ans = groupAnagrams(a);
    for(auto it:ans){
        for(auto its:it){
            cout<<its<<" ";
        }
    }
}