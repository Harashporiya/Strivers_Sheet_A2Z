#include<bits/stdc++.h>
using namespace std;
void f(int i,vector<int>&v,vector<vector<int>>&ans,int n,int k,int s,vector<int>&nums){
    if(k==v.size()){
        if(s==n){
        ans.push_back(v);
    }
        return;
    }

    for(int index=i;index<nums.size();index++){
        v.push_back(nums[index]);
       f(index+1,v,ans,n,k,s+nums[index],nums);
       v.pop_back();
    
    }
}
vector<vector<int>> combinationSum(int n,int k) {
      vector<vector<int>> ans;
      vector<int> nums(9,0);
      for(int i=0;i<9;i++){
        nums[i]=i+1;
      }
      vector<int> v;
      
      f(0,v,ans,n,k,0,nums);

      return ans;
}
int main(){
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<vector<int>>ans= combinationSum(n,k);
    
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
          cout<<ans[i][j]<<" ";
        }
        cout<<" ]";
    }
}