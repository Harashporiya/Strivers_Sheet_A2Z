#include<bits/stdc++.h>
using namespace std;
int countInversions(vector<int> &a, int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     
     int res = countInversions(a,n);
     cout<<res;
}