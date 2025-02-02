#include<bits/stdc++.h>
using namespace std;
vector<int> maximumSumCombinations(vector<int> &a, vector<int> &a1, int n, int k){
    priority_queue<int, vector<int>, greater<int>>minHeap;
    vector<int> res;
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            res.push_back(a[i]+a1[j]);
        }
    }

    for(int i=0;i<res.size();i++){
        minHeap.push(res[i]);
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    vector<int> ans;
    while(!minHeap.empty()){
     ans.push_back(minHeap.top());
     minHeap.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
  int n;
  cin>>n;
  vector<int> a(n),a1(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>a1[i];
  }
  int k;
  cin>>k;

  vector<int> ans  = maximumSumCombinations(a,a1,n,k);
  for(auto it:ans){
    cout<<it<<" ";
  }
}