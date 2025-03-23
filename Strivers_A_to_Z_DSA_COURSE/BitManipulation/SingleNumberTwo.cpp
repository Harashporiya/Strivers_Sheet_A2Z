#include<bits/stdc++.h>
using namespace std;
int singleNumberTwo(vector<int> &a, int n){
     // map<int, int> mpp;
        // for(auto it:a){
        //     mpp[it]++;
        // }

        // for(auto it:mpp){
        //     if(it.second == 1){
        //         return it.first;
        //     }
        // }
        // return 0;


    //     sort(a.begin(), a.end());
    //     for(int i=1;i<a.size();i+=3){
    //         if(a[i]!=a[i-1]){
    //             return a[i-1];
    //         }
    //     }
    //    return a[a.size()-1];


    int twos=0;
    int ones=0;
    for(int i=0;i<n;i++){
        ones = (ones^a[i]) & ~twos;
        twos = (twos^a[i]) & ~ones;
    }
    return ones;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<singleNumberTwo(a,n);
}