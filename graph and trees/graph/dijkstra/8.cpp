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

// int this question we have to find the minimu weight of subgraph so that we can reach destination from source1 and sorce 2;

// my mistake -> dijkstara1 for src1 to src2 and dijksrtra 2 for src2 to dest;
// we have to check for every i -> src1-> i && src2->i && i-> dest for this reverse graph (dest->i) -> VISULAIZE LIKE LCA IN TREE;
class Solution {
public:
    void dijkstra(int src,unordered_map<long long,list<pair<long long,long long>>>& adjList,vector<long long>& dis){
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,src});
        dis[src]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long node=it.second;
            long long dist=it.first;
            if(dis[node]< dist) continue;
            for(auto nbr:adjList[node]){
                if(nbr.second+dist<dis[nbr.first]){
                    dis[nbr.first]=nbr.second+dist;
                    pq.push({dis[nbr.first],nbr.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        int m=edges.size();
        unordered_map<long long,list<pair<long long,long long>>> adjList1;
        unordered_map<long long,list<pair<long long,long long>>> adjList2;
        for(int i=0;i<m;i++){
            long long u=edges[i][0];
            long long v=edges[i][1];
            long long w=edges[i][2];
            adjList1[u].push_back({v,w});
            adjList2[v].push_back({u,w});
        }
        vector<long long> dis1(n,LLONG_MAX);
        vector<long long> dis2(n,LLONG_MAX);
        vector<long long> dis3(n,LLONG_MAX);
        dijkstra(src1,adjList1,dis1);
        dijkstra(src2,adjList1,dis2);
        dijkstra(dest,adjList2,dis3);
        if(dis1[dest]==LLONG_MAX || dis2[dest]==LLONG_MAX) return -1;
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            if (dis1[i] == LLONG_MAX || dis2[i] == LLONG_MAX || dis3[i] == LLONG_MAX) continue;
            long long ele=dis1[i]+dis2[i]+dis3[i];
            ans=min(ans,ele);
        }
        return ans;
    }
};