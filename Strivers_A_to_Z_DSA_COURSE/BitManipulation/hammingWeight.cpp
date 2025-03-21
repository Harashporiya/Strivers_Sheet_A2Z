#include<bits/stdc++.h>
using namespace std;
int hammingWeight(int n) {
        // string ans;
        // while(n!=0){
        //     if(n%2==1){
        //         ans+="1";
        //     }else{
        //         ans+="0";
        //     }
        //     n/=2;
        // }
        // reverse(ans.begin(),ans.end());
        // int cnt=0;
        // for(int i=0;i<ans.length();i++){
        //     if(ans[i]=='1'){
        //         cnt++;
        //     }
        // }
        // return cnt;
        int cnt=0;
        while(n>0){
            cnt += n & 1;
            n>>=1;
        }
        return cnt;
}
int main(){
    int n;
    cin>>n;
    cout<<hammingWeight(n);
}