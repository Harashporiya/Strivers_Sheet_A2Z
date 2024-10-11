#include<bits/stdc++.h>
using namespace std;
// solve question help the lower bound and upper bound , and frist occurence
int lowerBound(vector<int> &a, int n, int x){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]>=x){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int RowWithMaxOne(vector<vector<int>> &a, int n, int m) {
   int cnt_max=0;
   int index=-1;
   for(int i=0;i<n;i++){
    int cnt_ones = m - lowerBound(a[i], m, 1);
    if(cnt_ones> cnt_max){
        cnt_max=cnt_ones;
        index=i;
    }
   }
   return index;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
   
    int result = RowWithMaxOne(a, n, m);
    
   cout<<result;
    
    return 0;
}
