//Question 1.-> // Given Row and col teel the element at that place R=5, C=3,
#include<iostream>
using namespace std;
int funcNCR(int n, int r){
   int res=1;
   for(int i=0;i<r;i++){
    res=res*(n-i);
    res=res/(i+1);
   }
   return res;
}
int main(){
    int n;
    cin>>n;
    int r;
    cin>>r;
    int ans = funcNCR(n-1,r-1);
    cout<<ans;
}