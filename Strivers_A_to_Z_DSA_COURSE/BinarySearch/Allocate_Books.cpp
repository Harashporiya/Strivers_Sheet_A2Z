#include<bits/stdc++.h>
using namespace std;
int sum(vector<int> &a, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}
bool isValid(vector<int> &a, int n, int s, int mid){
    int cntStud=1;
    int pageCount=0;
    for(int i=0;i<n;i++){
        if(a[i]>mid){
            return false;
        }
        if(pageCount+a[i]<=mid){
            pageCount+=a[i];
        }else{
            cntStud++;
            pageCount = a[i];
        }
    }
      if(cntStud<=s){
            return true;
        }else if(cntStud>s){
        return false;
        }
        return false;
}
int booksAllocated(vector<int> &a, int n, int s){
    if(s>n){
        return -1;
    }
    int low=0;
    int high=sum(a,n);
    int ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(isValid(a,n,s,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s;
    cin>>s;
    int ans = booksAllocated(a,n,s);
    cout<<ans;
}