#include<bits/stdc++.h>
using namespace std;
void swapToNumber(int &a, int &b){
  a=a^b;
  b=a^b;
  a=a^b;
  cout<<a<<b;
}
int main(){
    int a,b;
    cin>>a>>b;
    swapToNumber(a,b);
}