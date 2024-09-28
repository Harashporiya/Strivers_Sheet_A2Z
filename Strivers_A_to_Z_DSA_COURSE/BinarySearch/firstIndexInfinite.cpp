#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &a, int n, int k, int low, int high){
    int ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(a[mid]==k){
          ans = mid;
          high = mid-1;
        }else if(a[mid]<k){
           low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int infiniteSearch(vector<int> &a, int n, int k){
   int low=0;
    int high=1;
    while(k>a[high]){
      low=high;
      high=high*2;
    }
    
   return binarySearch(a,n,k,low,high);
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

   int ans = infiniteSearch(a,n,k);
   cout<<ans;
    
}