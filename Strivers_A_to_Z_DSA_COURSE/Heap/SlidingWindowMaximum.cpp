#include<bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMaximum(vector<int> &a, int k){
    priority_queue<int> maxHeap;
    vector<int> ans;

    for(int i=0;i<a.size();i++){
        if(maxHeap.size()>=k){
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }
        maxHeap.push(a[i]);
    }

    return ans;

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
    vector<int> res = slidingWindowMaximum(a,k);
    for(auto it:res){
        cout<<it<<" ";
    }
}