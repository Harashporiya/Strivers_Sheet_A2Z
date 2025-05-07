//Maximum of all subarrays of size k
#include<bits/stdc++.h>
using namespace std;
vector<int> maxiumOfAllSubArrays(vector<int> &a, int n, int k){
    vector<int> res;
    deque<int> q;
    int i=0,j=0;

    while(j<n){
        while(q.size()>0 && q.back()<a[j]){
            q.pop_back();
        }
        q.push_back(a[j]);
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            res.push_back(q.front());
            if(q.front() == a[i]){
                q.pop_front();
            }
            i++;j++;
        }

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
    vector<int> ans = maxiumOfAllSubArrays(a,n,k);
    for(int it:ans){
        cout<<it<<" ";
    }
}