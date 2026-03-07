#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------
1. BRUTE FORCE APPROACH (O(n^2))
Try every rotation and calculate flips
---------------------------------------
*/
int bruteForce(string s) {
    int n = s.size();
    int ans = INT_MAX;

    for(int r = 0; r < n; r++) {
        string rotated = s.substr(r) + s.substr(0, r);

        int flip1 = 0, flip2 = 0;

        for(int i = 0; i < n; i++) {
            char p1 = (i % 2 == 0) ? '0' : '1';
            char p2 = (i % 2 == 0) ? '1' : '0';

            if(rotated[i] != p1) flip1++;
            if(rotated[i] != p2) flip2++;
        }

        ans = min(ans, min(flip1, flip2));
    }

    return ans;
}


/*
---------------------------------------
2. YOUR APPROACH (Even/Odd Count)
Sliding Window + Counting
---------------------------------------
*/
int yourApproach(string s) {

    int n = s.size();
    s = s + s;

    int evenZero = 0, evenOne = 0;
    int oddZero = 0, oddOne = 0;

    int ans = INT_MAX;
    int l = 0;

    for(int r = 0; r < s.size(); r++) {

        if(r % 2 == 0){
            if(s[r] == '0') evenZero++;
            else evenOne++;
        } 
        else{
            if(s[r] == '0') oddZero++;
            else oddOne++;
        }

        if(r - l + 1 > n){
            if(l % 2 == 0){
                if(s[l] == '0') evenZero--;
                else evenOne--;
            } 
            else{
                if(s[l] == '0') oddZero--;
                else oddOne--;
            }
            l++;
        }

        if(r - l + 1 == n){
            int flip1 = evenOne + oddZero;
            int flip2 = evenZero + oddOne;
            ans = min(ans, min(flip1, flip2));
        }
    }

    return ans;
}


/*
---------------------------------------
3. OPTIMAL APPROACH (Pattern + Sliding Window)
Most popular solution
---------------------------------------
*/
int optimalApproach(string s) {

    int n = s.size();
    string t = s + s;

    int diff1 = 0, diff2 = 0;
    int ans = INT_MAX;

    for(int i = 0; i < 2*n; i++){

        if(t[i] != (i%2 ? '1' : '0')) diff1++;
        if(t[i] != (i%2 ? '0' : '1')) diff2++;

        if(i >= n){
            if(t[i-n] != ((i-n)%2 ? '1' : '0')) diff1--;
            if(t[i-n] != ((i-n)%2 ? '0' : '1')) diff2--;
        }

        if(i >= n-1){
            ans = min(ans, min(diff1, diff2));
        }
    }

    return ans;
}


/*
---------------------------------------
MAIN FUNCTION (VS CODE RUN)
---------------------------------------
*/

int main() {

    string s;
    cout << "Enter binary string: ";
    cin >> s;

    cout << "\nBrute Force Result: " << bruteForce(s) << endl;
    cout << "Your Approach Result: " << yourApproach(s) << endl;
    cout << "Optimal Approach Result: " << optimalApproach(s) << endl;

    return 0;
}