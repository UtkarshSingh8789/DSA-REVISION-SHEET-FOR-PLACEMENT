#include<bits/stdc++.h>
using namespace std;
//MHT is central Node;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        int m=edges.size();
        vector<int> indegree(n,0);
        unordered_map<int,vector<int>> adjList;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            ans.clear();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                ans.push_back(it);
                for(auto nbr:adjList[it]){
                    indegree[nbr]--;
                    if(indegree[nbr]==1){
                        q.push(nbr);
                    }
                }
            }
        }
        return ans;
    }
};