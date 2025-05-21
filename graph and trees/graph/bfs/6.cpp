#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n=graph.size();
        int m=initial.size();
        sort(initial.begin(), initial.end());
        int ans=-1;
        int count=INT_MAX;
        for(int i=0;i<m;i++){
            int remove_node=initial[i];
            unordered_map<int,list<int>> adjList;
            unordered_map<int,bool> visited;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(j!=remove_node && k!=remove_node){
                        if(graph[j][k]==1){
                            adjList[j].push_back(k);
                        }
                    }
                }
            }
            queue<int> q;
            for(int l=0;l<m;l++){
                if(l!=i){
                    if(!visited[initial[l]]){
                        q.push(initial[l]);
                        visited[initial[l]]=true;
                    }
                }
            }
            int count1=0;
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                count1=count1+1;
                for(auto nbr:adjList[it]){
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        q.push(nbr);
                    }
                }
            }
            if(count1<count){
                count=count1;
                ans=remove_node;
            }
        }
        return ans;
    }
};