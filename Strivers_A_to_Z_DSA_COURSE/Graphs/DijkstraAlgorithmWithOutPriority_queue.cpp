#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstraAlgorithm(int v,vector<vector<int>> &edges,int src){
   

    vector<vector<pair<int,int>>> adj(v);

    for(int i=0;i<v;i++){
      adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
      adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }

    vector<int> dist(v,1e9);
    dist[src]=0;

    set<pair<int,int>>st;
    st.insert({0,src});

    while(!st.empty()){
      auto it=*(st.begin());
      int node=it.second;
      int dis=it.first;

      st.erase(st.begin());

      for(auto it:adj[node]){
        int adjNode=it.first;
        int edW=it.second;

        if(dis+edW<dist[adjNode]){
          if(dist[adjNode]!=1e9){
            st.erase({dist[adjNode],adjNode});
          }
          dist[adjNode]=dis+edW;
          st.insert({dist[adjNode],adjNode});
        }
      }
    }
    return dist;
}
int main(){
  vector<vector<int>> edges={
     {0,1,4},{0,2,8},{1,4,6},{1,2,3},{2,3,2},{3,4,10}
  };

  int src=0;
  int v=5;

  vector<int> ans=dijkstraAlgorithm(v,edges,src);

  for(auto it:ans){
    cout<<it<<" ";
  }
}