#include<bits/stdc++.h>
using namespace std;
int longestSuccessiveElements(vector<int>&a) {
    sort(a.begin(), a.end());
    int n = a.size();
    int count=0;
    int lastSmollest=INT_MIN;
    int longest = 1;
    for(int i=0;i<n;i++){
        if(a[i]-1 == lastSmollest){
            count++;
            lastSmollest = a[i];
        }else if(a[i] != lastSmollest){
            count=1;
            lastSmollest=a[i];
        }
        longest=max(longest,count);
    }
    return longest;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

   int ans = longestSuccessiveElements(a);
   cout<<ans;
}