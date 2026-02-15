#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        
        int n=a.size();
        int m=b.size();

        if(n<m){
            for(int i=0;i<m-n;i++){
                a='0'+a;
            }
        }else{
            for(int i=0;i<n-m;i++){
                b='0'+b;
            }
        }

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int carry=0;
        for(int i=0;i<a.size();i++){
           if(a[i]=='1'&&b[i]=='1'&& carry==0){
             ans+='0';
             carry=1;
           }else if(a[i]=='1'&&b[i]=='0'&& carry==0){
             ans+='1';
           }else if(a[i]=='0'&&b[i]=='1'&& carry==0){
             ans+='1';
           }else if(a[i]=='1'&&b[i]=='1'&& carry==1){
             ans+='1';
             carry=1;
           }else if(a[i]=='0'&&b[i]=='1'&& carry==1){
             ans+='0';
             carry=1;
           }else if(a[i]=='1'&&b[i]=='0'&& carry==1){
             ans+='0';
             carry=1;
           }else if(a[i]=='0'&&b[i]=='0'&& carry==1){
             ans+='1';
             carry=0;
           }else if(a[i]=='0'&&b[i]=='0'&& carry==0){
             ans+='0';
           }
        }

        if(carry==1){
            ans+='1';
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    string a, b;
    cout << "Enter first binary string: ";
    cin >> a;
    cout << "Enter second binary string: ";
    cin >> b;

    string result = sol.addBinary(a, b);

    cout << "Sum: " << result << endl;

    return 0;
}
