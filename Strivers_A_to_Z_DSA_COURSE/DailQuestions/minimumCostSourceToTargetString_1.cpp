#include<bits/stdc++.h>
using namespace std;
long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source.size()!=target.size()){
            return -1;
        }

        vector<vector<long long>> dist(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }

        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';

            dist[u][v]=min(dist[u][v],(long long)cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        long long ans=0;

        for(int i=0;i<source.size();i++){
            int a=source[i]-'a';
            int b=target[i]-'a';

            if(dist[a][b]==INT_MAX){
                return -1;
            }
            ans+=dist[a][b];
        }

        return ans;
}
int main(){
    string src="abcd";
    string target="acbe";
    vector<char> original = {'a','b','c','c','e','d'};
    vector<char> change = {'b','c','d','e','b','e'};
    vector<int> cost={2,5,5,1,2,20};


    cout<<minimumCost(src,target,original,change,cost);
}