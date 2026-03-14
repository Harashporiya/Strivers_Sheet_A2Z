#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////
// Approach 1: Generate all happy strings and store
/////////////////////////////////////////////////////////

class Solution1 {
public:
    void f(int i,string st,vector<string>&ans,int n){
        if(i==n){
            ans.push_back(st);
            return;
        }

        if(st.empty() || st.back()!='a')
            f(i+1,st+'a',ans,n);

        if(st.empty() || st.back()!='b')
            f(i+1,st+'b',ans,n);

        if(st.empty() || st.back()!='c')
            f(i+1,st+'c',ans,n);
    }

    string getHappyString(int n,int k){
        vector<string> ans;
        f(0,"",ans,n);

        if(ans.size()<k) return "";
        return ans[k-1];
    }
};

/////////////////////////////////////////////////////////
// Approach 2: Backtracking without storing all strings
/////////////////////////////////////////////////////////

class Solution2 {
public:
    void f(int i,string &st,string &ans,int n,int k,int &count){
        if(i==n){
            count++;
            if(count==k) ans=st;
            return;
        }

        if(ans!="") return;

        if(st.empty() || st.back()!='a'){
            st.push_back('a');
            f(i+1,st,ans,n,k,count);
            st.pop_back();
        }

        if(st.empty() || st.back()!='b'){
            st.push_back('b');
            f(i+1,st,ans,n,k,count);
            st.pop_back();
        }

        if(st.empty() || st.back()!='c'){
            st.push_back('c');
            f(i+1,st,ans,n,k,count);
            st.pop_back();
        }
    }

    string getHappyString(int n,int k){
        string ans="";
        string st="";
        int count=0;

        f(0,st,ans,n,k,count);
        return ans;
    }
};

/////////////////////////////////////////////////////////
// Approach 3: Optimal (Math / Greedy)
/////////////////////////////////////////////////////////

class Solution3 {
public:
    string getHappyString(int n,int k){
        int total = 3 * pow(2,n-1);
        if(k>total) return "";

        string result="";
        vector<char> chars={'a','b','c'};

        int prev=-1;

        for(int i=0;i<n;i++){
            int block = pow(2,n-i-1);

            for(int j=0;j<3;j++){
                if(j==prev) continue;

                if(k>block){
                    k-=block;
                }else{
                    result.push_back(chars[j]);
                    prev=j;
                    break;
                }
            }
        }

        return result;
    }
};

/////////////////////////////////////////////////////////
// MAIN FUNCTION (No user input)
/////////////////////////////////////////////////////////

int main(){

    int n = 3;
    int k = 9;

    Solution1 s1;
    Solution2 s2;
    Solution3 s3;

    cout<<"Approach 1 (Store all): "<<s1.getHappyString(n,k)<<endl;
    cout<<"Approach 2 (Backtracking count): "<<s2.getHappyString(n,k)<<endl;
    cout<<"Approach 3 (Optimal math): "<<s3.getHappyString(n,k)<<endl;

    return 0;
}