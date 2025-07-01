#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> adj;
    adj.push_back({2, 3, 1}); 
    adj.push_back({0});      
    adj.push_back({0, 4});   
    adj.push_back({0});      
    adj.push_back({2});      

    for(int i = 0; i < adj.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
