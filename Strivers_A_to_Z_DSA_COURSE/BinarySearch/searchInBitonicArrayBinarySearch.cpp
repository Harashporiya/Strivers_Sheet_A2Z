#include<iostream>
using namespace std;
int peakElements(int a[], int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
            return mid;
        }
        if(a[mid]<a[mid+1]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
   return -1;
}
int SearchInbitonicArrayLeft(int a[], int n, int k){
    int low=0;
    int high = peakElements(a,n);
    while(low<=high){
        int mid = low+(high-low)/2;
        if(a[mid]==k){
            return mid;
        }else if(a[mid]<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int SearchInbitonicArrayRight(int a[], int n, int k){
    int low=peakElements(a,n)+1;
    int high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(a[mid]==k){
            return mid;
        }else if(a[mid]<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int peak = peakElements(a,n);
    cout<<"Peak "<<peak<<endl;
    int ans1 = SearchInbitonicArrayLeft(a,n,k);
    cout<<"ans1 "<<ans1<<endl;
    int ans2 = SearchInbitonicArrayRight(a,n,k);
    cout<<"ans2 "<<ans2<<endl;
    if(ans1==-1 && ans2==-1){
        cout<<ans1;
    }else if(ans1!=-1){
        cout<<ans1;
    }else if(ans2!=-1){
        cout<<ans2;
    }
}