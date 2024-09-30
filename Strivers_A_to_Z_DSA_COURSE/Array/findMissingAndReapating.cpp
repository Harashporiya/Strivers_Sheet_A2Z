#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int missing=-1, repeating=-1;
    // for(int i=1;i<=n;i++){
    //     int count=0;
    //     for(int j=0;j<n-1;j++){
    //         if(a[i]==i){
    //            count++;
    //         }
    //     }
    //     if(count<=2){
    //      repeating=i;
    //     }else if(count==0){
    //         missing=i;
    //     }
        // if(missing!=-1 && repeating!=-1){
        //     break;
        // }
    // }
    // cout<<repeating<<" "<<missing;
    map<int, int> mpp;
    for(int i=1;i<=n;i++){
        mpp[a[i-1]]++;
    }
    for(int i=1;i<=n;i++){
        if(mpp[i]<=2){
            repeating=i;
        }else if(mpp[i]==0){
            missing=i;
        }
         if (missing != -1 && repeating != -1) {
            break;
        }
    }
    cout<<repeating<<" "<<missing;
}