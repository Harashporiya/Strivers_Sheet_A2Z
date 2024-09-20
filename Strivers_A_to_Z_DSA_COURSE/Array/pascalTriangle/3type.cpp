//Question 2.-> Print all pascal triangle.
#include<iostream>
using namespace std;
void funcNCR(int n){
   int res=1;
   cout<<res<<" ";
   for(int i=1;i<n;i++){
    res=res*(n-i)/i;
    
    cout<<res<<" ";
   }
   
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    funcNCR(i);
    }
     
    
}