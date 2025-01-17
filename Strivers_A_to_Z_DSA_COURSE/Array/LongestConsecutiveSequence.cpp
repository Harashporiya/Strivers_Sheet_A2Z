#include<bits/stdc++.h>
using namespace std;
int longestConsective(vector<int> &a){
    unordered_set<int> st(a.begin(),a.end());
    int maxi=0;

    for(int it:st){
        if(st.find(it-1) == st.end()){
            int length=1;
            while(st.find(it+length) != st.end()){
                length++;
            }
            maxi=max(maxi,length);
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans = longestConsective(a);
    cout<<ans;
}