#include<bits/stdc++.h>
using namespace std;
int minimumDeletions(string s){
  int bcount=0;
      int ans=0;

      for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            ans=min(ans+1,bcount);
        }else{
            bcount++;
        }
      }
      return ans;
}
int main(){
    string s;
    cin>>s;

    cout<<minimumDeletions(s);
}