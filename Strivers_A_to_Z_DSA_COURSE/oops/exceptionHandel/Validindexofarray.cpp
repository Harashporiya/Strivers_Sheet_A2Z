#include<iostream>
using namespace std;
void VaildIndexArray(int a[], int n, int index){
 try{
    for(int i=0;i<n;i++){
        if(i == index){
            throw a[i];
        }
      
    }
     for(int i=0;i<n;i++){
       
        if(i != index){
            throw 'n';
        }
    }
 }catch(int ar){
    cout<<ar<<endl;
 }catch(char e){
    if(e=='n'){
        cout<<"Out of Bounds"<<endl;
    }
 }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int index;
        cin>>index;
        VaildIndexArray(a,n,index);
    }
}