#include<bits/stdc++.h>
using namespace std;
int kthSmollestElements(vector<int> &a, int n, int k){
    priority_queue<int> maxHeap;
    for(int i=0;i<n;i++){
        maxHeap.push(a[i]);
        if(maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    return maxHeap.top();
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