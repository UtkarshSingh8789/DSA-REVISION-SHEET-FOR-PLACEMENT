#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int m=edges.size();
        if(m==0) return 1;
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2]+1;
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n,1e9);
        pq.push({0,0});
        dis[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int w=it.first;
            int node=it.second;
            if(w>dis[node]) continue;
            for(auto nbr:adjList[node]){
                if(dis[nbr.first]>w+nbr.second){
                    dis[nbr.first]=w+nbr.second;
                    pq.push({dis[nbr.first],nbr.first});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dis[i]<=maxMoves) ans++;
        }
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            int remaining_u=0;
            int remaining_v=0;
            if(dis[u]<=maxMoves){
                remaining_u=maxMoves-dis[u];
            }
            if(dis[v]<=maxMoves){
                remaining_v=maxMoves-dis[v];
            }
            ans=ans+min(w,remaining_u+remaining_v);
        }
        return ans;
    }
};