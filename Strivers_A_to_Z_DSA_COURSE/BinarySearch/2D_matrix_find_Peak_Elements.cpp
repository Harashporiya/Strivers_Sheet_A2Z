#include<bits/stdc++.h>
using namespace std;
int findIndex(vector<vector<int>> &a, int n, int col, int m){
    int maxValue=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        if(a[i][col]>maxValue){
            maxValue=a[i][col];
            index=i;
        }
    }
     return index;
}
vector<int> peakElements(vector<vector<int>> &a, int n, int m){
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        int rowIndex = findIndex(a,n,mid,m);
        int left = m - 1 >=0 ? a[rowIndex][mid-1] : -1;
        int right = m+1<m ? a[rowIndex][mid+1]: -1;
        if(a[rowIndex][mid] > left && a[rowIndex][mid]> right){
            return {rowIndex, mid};
        }else if(a[rowIndex][mid]<left){
            high=mid-1;
        }else{
            low=mid+1;
        }

    }
    return {-1,-1};
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    vector<int> ans = peakElements(a,n,m);
    for(auto it:ans){
        cout<<it<<" ";
    }

}