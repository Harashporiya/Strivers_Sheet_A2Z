#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ---------------- APPROACH 1 ----------------
    // Generate all binary strings
    void generate(int i, string &s, vector<string> &res, int n){
        if(i == n){
            res.push_back(s);
            return;
        }

        s[i] = '0';
        generate(i+1, s, res, n);

        s[i] = '1';
        generate(i+1, s, res, n);
    }

    string bruteForce(vector<string>& nums){
        int n = nums.size();

        vector<string> all;
        string s(n,'0');

        generate(0,s,all,n);

        unordered_set<string> st(nums.begin(),nums.end());

        for(auto &it : all){
            if(!st.count(it))
                return it;
        }

        return "";
    }


    // ---------------- APPROACH 2 ----------------
    // Binary to Integer
    string integerMethod(vector<string>& nums){

        int n = nums.size();
        unordered_set<int> st;

        for(auto &s: nums){
            int val = stoi(s,0,2);
            st.insert(val);
        }

        for(int i=0;i<(1<<n);i++){
            if(!st.count(i)){
                string res="";
                for(int j=n-1;j>=0;j--){
                    res += ((i>>j)&1)+'0';
                }
                return res;
            }
        }

        return "";
    }


    // ---------------- APPROACH 3 ----------------
    // Backtracking with early stop
    string ans="";

    void solve(int i,string &s,unordered_set<string>&st,int n){

        if(i==n){
            if(!st.count(s))
                ans=s;
            return;
        }

        if(ans!="") return;

        s[i]='0';
        solve(i+1,s,st,n);

        s[i]='1';
        solve(i+1,s,st,n);
    }

    string backtracking(vector<string>& nums){

        int n=nums.size();
        unordered_set<string> st(nums.begin(),nums.end());

        string s(n,'0');
        ans="";

        solve(0,s,st,n);

        return ans;
    }


    // ---------------- APPROACH 4 ----------------
    // Cantor Diagonal Trick (Optimal)
    string diagonalMethod(vector<string>& nums){

        int n=nums.size();
        string res="";

        for(int i=0;i<n;i++){

            if(nums[i][i]=='0')
                res+='1';
            else
                res+='0';
        }

        return res;
    }

};


int main(){

    vector<string> nums={"01","10"};

    Solution obj;

    string a1=obj.bruteForce(nums);
    string a2=obj.integerMethod(nums);
    string a3=obj.backtracking(nums);
    string a4=obj.diagonalMethod(nums);

    return 0;
}