#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        int s0 = 0, s1 = 0;

        for(int i = 0; i < s.size(); i++){
            char f1 = (i % 2 == 0) ? '1' : '0';
            char f0 = (i % 2 == 0) ? '0' : '1';

            if(s[i] == f1){
                s1++;
            }
            if(s[i] == f0){
                s0++;
            }
        }

        return min(s1, s0);
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter binary string: ";
    cin >> s;

    int result = obj.minOperations(s);

    cout << "Minimum operations: " << result << endl;

    return 0;
}