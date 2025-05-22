#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0;i<m;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adjList[u].push_back({v,w});
        }
        vector<int> dis(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,src}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int count=it.second.first;
            int node=it.second.second;
            if(stop>k) continue;
            for(auto nbr:adjList[node]){
                if(stop<=k && dis[nbr.first]>count+nbr.second){
                    dis[nbr.first]=count+nbr.second;
                    q.push({stop+1,{dis[nbr.first],nbr.first}});
                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};