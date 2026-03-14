#include<bits/stdc++.h>
using namespace std;
void f(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it.first]){
            f(it.first,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int v,vector<vector<int>>&edges){
    vector<vector<pair<int,int>>> adj(v);

    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    vector<int> vis(v,0);
    stack<int> st;

    for(int i=0;i<v;i++){
        if(!vis[i]){
            f(i,adj,vis,st);
        }
    }

    vector<int> dist(v,1e9);
    dist[0]=0;

    while(!st.empty()){
         int node=st.top();
         st.pop();
         
         if(dist[node]!=1e9){
            for(auto it:adj[node]){
            int adjNode=it.first;
            int adjWt=it.second;
            if(dist[node]+adjWt<dist[adjNode]){
                dist[adjNode]=dist[node]+adjWt;
            }
         }
         }
    }

    for(int i=0;i<v;i++){
        if(dist[i]==1e9){
            dist[i]=-1;
        }
    }
    return dist;
}
int main(){
    int v=6,e=7;

    vector<vector<int>> edges={
      {0,1,2},
      {0,4,1},
      {4,5,4},
      {4,2,2},
      {1,2,3},
      {2,3,6}
    };

    vector<int> ans=shortestPath(v,edges);

    for(auto it:ans){
        cout<<it<<" ";
    }
}