#include<bits/stdc++.h>
using namespace std;
void f(int i,vector<int>&v,vector<vector<int>>&ans,vector<int>&candidates,int target){
    if(i==candidates.size()){
        if(target==0){
        ans.push_back(v);
    }
        return;
    }
    
    if(candidates[i]<=target){
        v.push_back(candidates[i]);
    f(i,v,ans,candidates,target-candidates[i]);
    v.pop_back();
    }
    f(i+1,v,ans,candidates,target);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> v;
      
      f(0,v,ans,candidates,target);

      return ans;
}
int main(){
    int n;
    cin>>n;

    vector<int>candidates(n);
    for(int i=0;i<n;i++){
        cin>>candidates[i];
    }

    int target;
    cin>>target;

    vector<vector<int>>ans= combinationSum(candidates,target);
    
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
          cout<<ans[i][j]<<" ";
        }
        cout<<" ]";
    }
}