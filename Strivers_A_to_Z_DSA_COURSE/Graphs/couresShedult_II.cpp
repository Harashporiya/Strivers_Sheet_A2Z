#include<bits/stdc++.h>
using namespace std;
vector<int>  findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
          for(auto it:adj[i]){
            indegree[it]++;
          }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;

     while(!q.empty()){
        int node=q.front();
        q.pop();
       topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
     }
     if(topo.size()==numCourses){
        return topo;
     }
     return{};
}
int main(){
    int n=4;

    vector<vector<int>> prerequisites={
        {1,0},{2,0},{3,1},{3,2}
    };

    vector<int> ans = findOrder(n,prerequisites);

    for(auto it:ans){
        cout<<it<<" ";
    }

}