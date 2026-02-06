#include<bits/stdc++.h>
using namespace std;
void f(int i,vector<int>&v,vector<vector<int>>&ans,vector<int>&candidates,int target){
    // if(i==candidates.size()){
        if(target==0){
        ans.push_back(v);
    // }
        return;
    }

    for(int index=i;index<candidates.size();index++){
        if(index>i && candidates[index]==candidates[index-1])continue;
      if(candidates[index]>target ){
        break;
      }
        v.push_back(candidates[index]);
       f(index+1,v,ans,candidates,target-candidates[index]);
       v.pop_back();
    
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> v;
      sort(candidates.begin(),candidates.end());
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