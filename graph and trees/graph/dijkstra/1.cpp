#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0;i<m;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long> dis(n,1e18);
        vector<int> ways(n,0);
        dis[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long count=it.first;
            int node=it.second;
            if(count>dis[node]) continue;
            for(auto nbr:adjList[node]){
                int v=nbr.first;
                int w=nbr.second;
                if(dis[v]>count+w){
                    dis[v]=count+w;
                    ways[v]=ways[node];
                    pq.push({dis[v],v});
                }
                else if(dis[v]==count+w){
                    ways[v]=(ways[v]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};
