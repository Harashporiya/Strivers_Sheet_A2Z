#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Fancy {
public:
    vector<int> v;
    ll sum = 0;
    ll mul = 1;
    ll mod = 1e9 + 7;

    Fancy() {}

    // Fast exponentiation
    ll power(ll base, ll exp) {
        ll ans = 1;
        base %= mod;
        while (exp) {
            if (exp & 1) ans = (ans * base) % mod;
            exp /= 2;
            base = (base * base) % mod;
        }
        return ans;
    }

    // Modular inverse
    ll modInverse(ll n) {
        return power(n, mod - 2);
    }

    void append(int val) {
        ll temp = val;
        // Normalize the value
        ll base = ((temp - sum + mod) % mod * modInverse(mul)) % mod;
        v.push_back(base);
    }

    void addAll(int inc) {
        sum = (sum + inc) % mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        sum = (sum * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size()) return -1;
        return (v[idx] * mul + sum) % mod;
    }
};

int main() {
    // Fancy class object
    Fancy fancy;

    // Sample operations
    fancy.append(2);        // Array: [2]
    fancy.addAll(3);        // Array: [5]
    fancy.append(7);        // Array: [5, 7] (internally normalized)
    fancy.multAll(2);       // Array: [10, 14]
    fancy.addAll(1);        // Array: [11, 15]

    // Get values
    cout << "Index 0: " << fancy.getIndex(0) << endl; // 11
    cout << "Index 1: " << fancy.getIndex(1) << endl; // 15
    cout << "Index 2: " << fancy.getIndex(2) << endl; // -1 (out of bounds)

    // More operations
    fancy.append(3);        // Append 3
    fancy.multAll(3);       // Multiply all by 3
    cout << "Index 2: " << fancy.getIndex(2) << endl; // (3 * 3 + cumulative additions) % mod

    return 0;
}