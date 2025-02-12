#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &a, int n, int k){
    int i=0,j=0;
    while(j<n){
        int m = i;
        while(m<j){
            if(a[m]==a[j]){
                return true;
            }
            m++;
        }
        j++;
        if(j-i>k){
            i++;
        }
    }
    return false;
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

    cout<<containsDuplicate(a,n,k);
}