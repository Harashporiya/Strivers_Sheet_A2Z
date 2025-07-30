#include<bits/stdc++.h>
using namespace std;
int knapSack(vector<int>&wt,vector<int>&val,int w,int n){
    if(w==0 || n==0){
        return 0;
    }

    if(wt[n-1]<=w){
        int include = val[n-1] + knapSack(wt, val, w - wt[n-1], n - 1);
        int exclude = knapSack(wt, val, w, n - 1);
        return max(include, exclude);
    }else if(wt[n-1]>w){
        return knapSack(wt,val,w,n-1);
    }
    return 0;
}
int main(){
    vector<int> wt={4,5,1};
    vector<int> val={1,2,3};
    int w=4;

    cout<<knapSack(wt,val,w,3);
}