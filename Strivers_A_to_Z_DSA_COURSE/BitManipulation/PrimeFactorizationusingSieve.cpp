#include<bits/stdc++.h>
using namespace std;

void sieve(vector<int>& primes, int N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

vector<int> findPrimeFactors(int N) {
    vector<int> primes;
    vector<int> factors;
    
    sieve(primes, N);
    
    for (int prime : primes) {
        while (N % prime == 0) {
            factors.push_back(prime);
            N /= prime;
        }
    }
    
    if (N > 1) {
        factors.push_back(N);
    }
    
    return factors;
}

int main() {
    int N;
    cin >> N;

    vector<int> factors = findPrimeFactors(N);
    for (int factor : factors) {
        cout << factor << " ";
    }

    return 0;
}