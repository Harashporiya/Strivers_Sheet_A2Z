#include<bits/stdc++.h>
using namespace std;
void f(int ind,vector<vector<int>>&ans,vector<int>&v,vector<int>&nums){
     ans.push_back(v);
    for(int i=ind;i<nums.size();i++){
           if(i>ind && nums[i]==nums[i-1])continue;
           v.push_back(nums[i]);
           f(i+1,ans,v,nums);
           v.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
       sort(ans.begin(),ans.end());
        f(0,ans,v,nums);

        return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> ans=subsets(arr);
    
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}