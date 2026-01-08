#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int>& a, vector<int>& b) {
    if (i == a.size() || j == b.size())
        return INT_MIN;

    int take = a[i] * b[j];
    int next = f(i + 1, j + 1, a, b);
    if (next != INT_MIN)
        take += max(0, next);

    int skipA = f(i + 1, j, a, b);
    int skipB = f(i, j + 1, a, b);

    return max({take, skipA, skipB});
}
int main() {
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};
    cout << f(0, 0, nums1, nums2) << endl;

    return 0;
}
