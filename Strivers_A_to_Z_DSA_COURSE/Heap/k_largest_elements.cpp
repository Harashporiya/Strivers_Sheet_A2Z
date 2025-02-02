#include<bits/stdc++.h>
using namespace std;
int kthlargest(vector<int>& hand, int groupSize) {
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
     int res = kthlargest(a,n,k);
     cout<<res;
    


}