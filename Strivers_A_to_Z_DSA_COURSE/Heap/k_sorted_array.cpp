#include<bits/stdc++.h>
using namespace std;
vector<int> kthSortedArray(vector<int> &a, int n, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> res;
    for(int i=0;i<n;i++){
        minHeap.push(a[i]);
        if(minHeap.size()>k){
            res.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
         res.push_back(minHeap.top());
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
     vector<int> res =  kthSortedArray(a,n,k);
     for(auto it:res){
        cout<<it<<" ";
     }
}