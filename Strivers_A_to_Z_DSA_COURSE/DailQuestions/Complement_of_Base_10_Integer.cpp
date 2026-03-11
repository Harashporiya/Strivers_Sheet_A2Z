#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:

    // -------------------------------
    // Approach 1: String Conversion
    // -------------------------------
    int bitwiseComplement_string(int n) {

        if(n == 0) return 1;

        string s = "";

        while(n > 0){
            int d = n % 2;
            s += to_string(d);
            n /= 2;
        }

        reverse(s.begin(), s.end());

        // Flip bits
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }

        reverse(s.begin(), s.end());

        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                ans += pow(2, i);
            }
        }

        return ans;
    }


    // ---------------------------------
    // Approach 2: Bit Mask (Best)
    // ---------------------------------
    int bitwiseComplement_mask(int n) {

        if(n == 0) return 1;

        int mask = 0;
        int temp = n;

        while(temp > 0){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return (~n) & mask;
    }


    // ---------------------------------
    // Approach 3: XOR Mask Trick
    // ---------------------------------
    int bitwiseComplement_xor(int n) {

        if(n == 0) return 1;

        int mask = 1;

        while(mask <= n){
            mask <<= 1;
        }

        return (mask - 1) ^ n;
    }


    // ---------------------------------
    // Approach 4: Bit by Bit Flip
    // ---------------------------------
    int bitwiseComplement_bitwise(int n) {

        if(n == 0) return 1;

        int ans = 0;
        int power = 1;

        while(n > 0){

            int bit = n & 1;

            if(bit == 0)
                ans += power;

            power <<= 1;
            n >>= 1;
        }

        return ans;
    }
};


int main(){

    Solution obj;

    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "\nUsing String Method: "
         << obj.bitwiseComplement_string(n) << endl;

    cout << "Using Bit Mask Method: "
         << obj.bitwiseComplement_mask(n) << endl;

    cout << "Using XOR Trick: "
         << obj.bitwiseComplement_xor(n) << endl;

    cout << "Using Bit-by-Bit Method: "
         << obj.bitwiseComplement_bitwise(n) << endl;

    return 0;
}