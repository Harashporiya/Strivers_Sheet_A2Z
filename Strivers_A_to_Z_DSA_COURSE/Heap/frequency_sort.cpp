#include<bits/stdc++.h>
using namespace std;
vector<int> frequencySort(vector<int> &a, int n){
   priority_queue<pair<int, int>> maxHeap;

   unordered_map<int, int> mpp;
   for(int i=0;i<n;i++){
    mpp[a[i]]++;
   }
   for(auto i=mpp.begin();i!=mpp.end();i++){
    maxHeap.push({i->second, i->first});
   }
   vector<int> res;
   while(!maxHeap.empty()){
    int fre = maxHeap.top().first;
    int ele = maxHeap.top().second;
    for(int i=0;i<fre;i++){
        res.push_back(ele);
    }
    maxHeap.pop();
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
     vector<int> res =  frequencySort(a,n);
    for(auto it:res){
        cout<<it<<" ";
    }
}