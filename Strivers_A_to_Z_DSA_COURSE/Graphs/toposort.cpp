#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& edges, stack<int> s,vector<int>&vis){
    vis[node]=1;

    for(auto it:edges[node]){
        if(!vis[it]){
            dfs(it,edges,s,vis);
        }
        s.push(node);
    }
}
vector<int> topoSort(int v,int e, vector<vector<int>>& edges){
    vector<int> vis(v,0);

    stack<int> s;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,edges,s,vis);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main(){
    int v=4,e=3;
    vector<vector<int>> edges={
        {3,0},{1,0},{2,0}
    };

    vector<int> ans = topoSort(v,e,edges);
    for(auto it:ans){
        cout<<it<<" ";
    }
}