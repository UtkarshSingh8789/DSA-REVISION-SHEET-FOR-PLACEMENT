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

// DP+DIJKSTAR -> MIXED CONCEPT INPORTANT;
class Solution {
public:  
    int dp[20001];
    unordered_map<int,vector<pair<int,int>>> adjList;
    vector<int> dis;
    const int MOD=1e9+7;
    int solve(int i,int n){
        if(i==(n-1)) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        for(auto nbr:adjList[i]){
            if(dis[i]>dis[nbr.first]){
                ans=(ans+solve(nbr.first,n))%MOD;
            }
        }
        return dp[i]=ans;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        for(auto& e:edges){
            int u=e[0]-1;
            int v=e[1]-1;
            int w=e[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis.resize(n,INT_MAX);
        dis[n-1]=0;
        pq.push({0,n-1});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int w=it.first;
            int node=it.second;
            if(dis[node]<w) continue;
            for(auto nbr:adjList[node]){
                if(dis[nbr.first]>w+nbr.second){
                    dis[nbr.first]=w+nbr.second;
                    pq.push({dis[nbr.first],nbr.first});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
    }
};
