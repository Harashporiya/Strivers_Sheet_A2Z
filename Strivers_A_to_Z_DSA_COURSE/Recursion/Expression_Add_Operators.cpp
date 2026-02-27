#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
   void f(int ind, long long current_val, long long lastoperand,
          vector<string>& ans, string s, string num, int t) {
       
     if(ind == num.size()){
        if(current_val == t){
            ans.push_back(s);
        }
        return;
     }

     for(int i = ind; i < num.size(); i++){
        // Prevent leading zero numbers like "05"
        if(i > ind && num[ind] == '0') return;

        string current_num = num.substr(ind, i - ind + 1);
        long long current_num_val = stoll(current_num);

        if(ind == 0){
          // First number (no operator before it)
          f(i + 1, current_num_val, current_num_val,
            ans, current_num, num, t);
        } 
        else{
            // Addition
            f(i + 1,
              current_val + current_num_val,
              current_num_val,
              ans,
              s + "+" + current_num,
              num, t);

            // Subtraction
            f(i + 1,
              current_val - current_num_val,
              -current_num_val,
              ans,
              s + "-" + current_num,
              num, t);

            // Multiplication
            f(i + 1,
              current_val - lastoperand + lastoperand * current_num_val,
              lastoperand * current_num_val,
              ans,
              s + "*" + current_num,
              num, t);
        }
     }
   }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        f(0, 0, 0, ans, "", num, target);
        return ans;
    }
};

int main() {
    Solution sol;

    string num;
    int target;

    cout << "Enter number string: ";
    cin >> num;

    cout << "Enter target: ";
    cin >> target;

    vector<string> result = sol.addOperators(num, target);

    cout << "\nExpressions that evaluate to target:\n";
    for(string expr : result){
        cout << expr << endl;
    }

    return 0;
}