#include<bits/stdc++.h>
using namespace std;
int minimumDeletions(string s){
    stack<char> st;
    int cnt=0;
    for(auto c:s){
        if(c=='b'){
            st.push(c);
        }else{
            if(!st.empty()){
                st.pop();
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    string s;
    cin>>s;

    cout<<minimumDeletions(s);
}