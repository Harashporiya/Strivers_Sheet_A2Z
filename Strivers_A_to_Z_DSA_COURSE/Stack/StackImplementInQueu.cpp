#include <bits/stdc++.h>
using namespace std;

void stackInQueue(vector<int> &a, int n) {
    queue<int> q;

    for (int i = 0; i < n; i++) 
        q.push(a[i]);

    int s = q.size();
    while (s--) {  // Rotate elements
        q.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) 
        cin >> x;

    stackInQueue(a, n);
    return 0;
}
