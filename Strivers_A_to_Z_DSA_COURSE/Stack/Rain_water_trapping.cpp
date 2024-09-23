#include<bits/stdc++.h>
using namespace std;
int rainWaterTrapping(vector<int> &a, int n){
    vector<int> maxl(n), maxR(n);
    maxl[0] = a[0];
    maxR[n-1] = a[n-1];

    for(int i=1;i<n;i++){
        maxl[i] = max(maxl[i-1], a[i]);
    }
     for(int i=n-2;i>=0;i--){
        maxR[i] = max(maxR[i+1], a[i]);
    }
    int water[n];
    for(int i=0;i<n;i++){
        water[i] = min(maxl[i], maxR[i])-a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=water[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
      
      int ans = rainWaterTrapping(a,n);
      cout<<ans;
}