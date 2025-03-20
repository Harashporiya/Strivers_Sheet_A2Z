#include<bits/stdc++.h>
using namespace std;
int removeLastbit(int n){
    return (n+1) | n;
}
int main(){
    int n;
    cin>>n;
    cout<<removeLastbit(n);
}