#include<bits/stdc++.h>
using namespace std;
int stringIsAtoi(string st){
    int i=0;
    int sign=1;
    long res=0;
    
    // space ignore
    while(i<st.size() && st[i]==' ') i++;
    if(i==st.size()) return 0;
   
   // handle + and -
    if(st[i]=='-'){
        sign=-1;
        i++;
    }else if(st[i]=='+'){
        i++;
    }


    while(i<st.size() && isdigit(st[i])){
        res=res*10 + (st[i] - '0');

        if(sign*res>INT_MAX) return INT_MAX;
        if(sign*res<INT_MIN) return INT_MIN;

        i++;
    }
    return (int)(sign*res);
}
int main(){
    string st;
    cin>>st;
    cout<<stringIsAtoi(st);
}