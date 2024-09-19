#include<iostream>
using namespace std;
void mergeSort(int a[], int l, int m, int r){
    int size1 = m - l+1;
    int size2 = r - m;

    int left[size1], right[size2];
    for(int i=0;i<size1;i++){
        left[i] = a[l+i];
    }
    for(int i=0;i<size2;i++){
        right[i] = a[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<size1 && j<size2){
        if(left[i]<=right[j]){
            a[k++] = left[i++];
        }else{
            a[k++] = right[j++];
        }
    }
    while(i<size1){
        a[k++] = left[i++];
    }
    while(j<size2){
        a[k++] = right[j++];
    }
}
void merge(int a[], int l, int r){
  if(l<r){
    int m = (l+r)/2;
    merge(a,l,m);
    merge(a,m+1,r);

    mergeSort(a,l,m,r);
  }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
         merge(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}