#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> search2DMatrix(vector<vector<int>> &a, int n, int m, int key) {
    int i = 0;
    int j = m - 1;
    vector<pair<int, int>> ans;
    
    while (i < n && j >= 0) {
        if (a[i][j] == key) {
            ans.push_back({i, j});
            j--; 
        } else if (a[i][j] > key) {
            j--; 
        } else {
            i++;
        }
    }

    return ans; 
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int key;
    cin >> key;
    
    vector<pair<int, int>> result = search2DMatrix(a, n, m, key);
    
    if (result.empty()) {
        cout << "Key not found" << endl;
    } else {
        for (auto &p : result) {
            cout << "Found at: (" << p.first << ", " << p.second << ")" << endl;
        }
    }
    
    return 0;
}
