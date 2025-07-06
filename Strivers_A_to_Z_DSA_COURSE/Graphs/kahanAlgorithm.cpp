#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(vector<vector<int>> &edges){
    int n=edges.size();
    
    vector<int> indegree(n, 0);
    for(int i=0;i<n;i++){
      for(auto it:edges[i]){
        indegree[it]++;
      }
    }

    queue<int> q;
     for(int i=0;i<n;i++){
        if(indegree[i]==0){
             q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);
       
        for(auto it:edges[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }


    }
    return topo;
}
int main(){
    vector<vector<int>> edges={
     {2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}
    };

    vector<int> ans = topoSort(edges);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}