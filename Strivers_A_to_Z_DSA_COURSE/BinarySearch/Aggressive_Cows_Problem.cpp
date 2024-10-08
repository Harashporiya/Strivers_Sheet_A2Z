#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool isPossible(vector<int> &a, int n, int cow, int mid){
    int cntCows=1;
    int last = a[0];
    for(int i=1;i<n;i++){
        if(a[i]-last >= mid){
            cntCows++;
            last=a[i];
        }
       if(cntCows==cow){
        return true;
       }
    }
    return false;
}
int aggressiveCows(vector<int> &a, int n, int cow){
    sort(a.begin(),a.end());
    int low=1;
    int high = a[n-1]-a[0];
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(a,n,cow,mid)){
            ans = mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
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
    int cow;
    cin>>cow;
    int ans = aggressiveCows(a,n,cow);
    cout<<ans;
}