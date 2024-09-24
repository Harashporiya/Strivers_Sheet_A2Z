#include<bits/stdc++.h>
using namespace std;
int containerWithMostWater(int a[], int n){
   int ans=0;
//    for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         int w=j-i;
//         int h = min(a[i], a[j]);
//         int currentWater = h*w;
//       ans = max(ans, currentWater);
//     }
//    }
   int left=0;
   int right=n-1;
   while(left<right){
    int width = right-left;
    int hight = min(a[left], a[right]);
    int currentAns = width*hight;
    ans=max(ans, currentAns);

    if(a[left]<a[right]){
        left++;
    }else{
        right--;
    }
   }
return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans = containerWithMostWater(a,n);
    cout<<ans;
}