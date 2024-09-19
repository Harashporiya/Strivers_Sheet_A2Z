#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }int even=0,odd=0;
    int pos[even], neg[odd];
    for(int i=0;i<n;i++){
        if(a[i]>0){
            pos[even++] = a[i];
        }else if(a[i]<0){
            neg[odd++] = a[i];
        }
    }

    for(int i=0;i<even,odd;i++){
      a[2*i] = pos[i];
      a[2*i+1] = neg[i]; 

      cout<<a[i]<<" ";
    }
}