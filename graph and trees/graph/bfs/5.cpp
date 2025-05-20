#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> col;
    unordered_map<int,vector<int>> adjList;
    bool dfs(int src,int prev){
        col[src]=prev;
        for(auto nbr:adjList[src]){
            if(col[nbr]==-1){
                if(!dfs(nbr,!prev)) return false;
            }
            else{
                if(col[nbr]==prev) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<graph[i].size();j++){
                adjList[i].push_back(graph[i][j]);
            }
        }
        col.resize(m,-1);
        for(int i=0;i<m;i++){
            if(col[i]==-1){
                if(!dfs(i,0)) return false;
            }
        }
        return true;
    }
};// a  graph is bipartiate if we can color the nodes with two different color so that no two adjacend nodes have same colo;
// formalLang->A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
int main(){

}