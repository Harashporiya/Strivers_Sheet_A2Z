#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool check = false;  // To track if we encounter '0'

        // Iterate through the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                check = true;  // Mark that we have encountered a '0'
            }

            if (s[i] == '1' && check) {
                // If '1' is found after '0', it means more than one segment
                return false;
            }
        }

        return true;  // If no multiple segments were found
    }
};

int main() {
    Solution sol;
    
    // Test cases
    string s1 = "1001";
    string s2 = "110";
    string s3 = "111";
    string s4 = "101";
    
    // Output results for the test cases
    cout << "Input: " << s1 << " => Output: " << (sol.checkOnesSegment(s1) ? "true" : "false") << endl;
    cout << "Input: " << s2 << " => Output: " << (sol.checkOnesSegment(s2) ? "true" : "false") << endl;
    cout << "Input: " << s3 << " => Output: " << (sol.checkOnesSegment(s3) ? "true" : "false") << endl;
    cout << "Input: " << s4 << " => Output: " << (sol.checkOnesSegment(s4) ? "true" : "false") << endl;

    return 0;
}