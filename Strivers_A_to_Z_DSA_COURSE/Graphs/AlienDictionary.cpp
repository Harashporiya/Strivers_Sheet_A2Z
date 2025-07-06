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
string findOrder(int k, int n, vector<string> &words) {
    vector<vector<int>> adj(k);
    for(int i=0;i<n;i++){
        string s1 = words[i];
        string s2 = words[i+1];
        int len = min(s1.size(),s2.size());

        for(int ptr=0;ptr<len;ptr++){
            if(s1[ptr]!=s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(adj);
   string ans="";
   for(auto it:topo){
    ans+=ans+char(it + 'a');
   }
   return ans;
    
}
int main(){
    int k=4;
    int n=5;
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    cout<<findOrder(k,n,words);
}