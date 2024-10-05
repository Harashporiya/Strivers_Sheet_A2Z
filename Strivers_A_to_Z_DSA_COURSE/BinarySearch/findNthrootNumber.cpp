// #include<bits/stdc++.h>
// using namespace std;
// int findNthRoot(int m,int n){
//     for(int i=0;i<=m;i++){
//            if(pow(i,n)==m){
//             return i;
//            }else if(pow(i,n)>m){
//             break;
//            }
//     }
//     return -1;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int ans =findNthRoot(m,n);
//     cout<<ans;
// }
#include<bits/stdc++.h>
using namespace std;
int findNthRoot( int n, int k){
    int low=1;
    int high = k-1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(pow(mid,n)==k){
            return mid;
        }else if(pow(mid,n)>k){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;

    
}
int main(){
    int n,k;
    cin>>n>>k;
    

    int ans = findNthRoot(n,k);
    cout<<ans;
}