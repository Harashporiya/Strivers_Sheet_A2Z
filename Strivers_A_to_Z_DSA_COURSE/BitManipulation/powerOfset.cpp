#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> powerOfSet(vector<int> &a, int n){
    int subset=1<<n;
    vector<vector<int>> ans;
    for(int i=0;i<subset;i++){
        vector<int> list;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                list.push_back(a[j]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> res = powerOfSet(a,n);
   for (auto &it : res) {
        cout << "[";
        for (int i = 0; i < it.size(); i++) {
            cout << it[i];
            if (i != it.size() - 1) cout << " ";
        }
        cout << "] ";
    }
}