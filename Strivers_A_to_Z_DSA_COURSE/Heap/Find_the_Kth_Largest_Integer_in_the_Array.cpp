#include<bits/stdc++.h>
using namespace std;
 string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, greater<string>> minHeap;
        for(int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    string ans = kthLargestNumber(a,k);
    cout<<ans;
}    