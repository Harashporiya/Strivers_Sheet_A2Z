#include<bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor){
    int sum=0;int cnt=0;
    while(sum+divisor<=dividend){
        cnt+=1;
        sum+=divisor;
    }
    return cnt;
}
int main(){
    int dividend;
     int divisor;
     cin>>dividend>>divisor;
     cout<<divide(dividend,divisor);

}