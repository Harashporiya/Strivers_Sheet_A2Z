#include<bits/stdc++.h>
using namespace std;
vector<int> kClosestNumber(vector<int> &a, int n, int k,int x){
   priority_queue<pair<int, int>> maxHeap;
   for(int i=0;i<n;i++){
    maxHeap.push({abs(a[i]-x),a[i]});
    if(maxHeap.size()>k){
        maxHeap.pop();
    }
   }

   vector<int> res;
   while(!maxHeap.empty()){
    res.push_back(maxHeap.top().second);
    maxHeap.pop();
   }
     sort(res.begin(),res.end());
   return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k,x;
    cin>>k>>x;
     vector<int> res =  kClosestNumber(a,n,k,x);
    for(auto it:res){
        cout<<it<<" ";
    }
}