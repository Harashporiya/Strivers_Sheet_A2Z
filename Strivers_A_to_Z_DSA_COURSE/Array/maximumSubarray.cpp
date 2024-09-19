#include<iostream>
using namespace std;
int main(){ 
    int n;
    cin>>n;
    int a[n];
    // int start,arrstart=-1,arrend=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    int maxi=a[0];
    // for(int i=0;i<n;i++){
    //     if(sum==0){
    //         start=i;
    //     }
    //    sum+=a[i];
    //    if(sum>maxi){
    //     maxi = sum;
    //     arrstart=start;
    //     arrend=i;
    //    }else if(sum<0){
    //      sum=0;
    //    }
    // }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum+=a[j];
          maxi=max(sum,maxi);
        }
    }
    cout<<maxi;
}