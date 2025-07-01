#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj){
    int n = adj.size();
    int vis[n] = {0};
     vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> ls;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ls.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return ls;
}

int main(){
    vector<vector<int>> adj;
    adj.push_back({2, 3, 1}); 
    adj.push_back({0});      
    adj.push_back({0, 4});   
    adj.push_back({0});      
    adj.push_back({2});   
    
   vector<int> ans = bfs(adj);
   for(auto it:ans){
    cout<<it<<" ";
   }


    return 0;
}
