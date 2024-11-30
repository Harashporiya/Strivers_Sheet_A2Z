#include<bits/stdc++.h>
using namespace std;
int kthSmollestElements(vector<int> &a, int n, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<n;i++){
        minHeap.push(a[i]);
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    return minHeap.top();
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
     int res =  kthSmollestElements(a,n,k);
     cout<<res;
}