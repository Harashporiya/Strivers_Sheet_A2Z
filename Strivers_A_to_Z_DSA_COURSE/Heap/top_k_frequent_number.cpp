#include<bits/stdc++.h>
using namespace std;
vector<int> topKFrequentNumber(vector<int> &a, int n, int k){
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

   unordered_map<int, int> mpp;
   for(int i=0;i<n;i++){
    mpp[a[i]]++;
   }
   for(auto i=mpp.begin();i!=mpp.end();i++){
    minHeap.push({i->second, i->first});
    if(minHeap.size()>k){
        minHeap.pop();
    }
   }
   vector<int> res;
   while(!minHeap.empty()){
    res.push_back(minHeap.top().second);
    minHeap.pop();
   }
   return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
     vector<int> res =  topKFrequentNumber(a,n,k);
    for(auto it:res){
        cout<<it<<" ";
    }
}