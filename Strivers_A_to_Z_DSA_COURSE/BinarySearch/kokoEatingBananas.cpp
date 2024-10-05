#include<bits/stdc++.h>
using namespace std;

int kokoEating(int a[], int n, int k) {
    int totalh = 0;
    for (int i = 0; i < n; i++) {
        totalh += (a[i] + k - 1) / k;  
    }
    return totalh;
}

int fun(int a[], int n, int h) {
    int maxi = *max_element(a, a + n);  
    int low = 1, high = maxi;

    while (low < high) {
        int mid = (low + high) / 2;
        int requiredTime = kokoEating(a, n, mid);
        if (requiredTime <= h) {
            high = mid;  
        } else {
            low = mid + 1;  
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int h;
    cin >> h;
    int ans = fun(a, n, h);
    cout << ans << endl;  
}
