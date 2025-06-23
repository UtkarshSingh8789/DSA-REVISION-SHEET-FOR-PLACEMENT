
//THEORY:

// a spannng tree is tree having n nodes and n-1 edges and all nodes are reachable from each others;
// kruskals for MST; ----> undirected graph connected have neigative weight but no negative cylcle;
// the tree having least sum of weights in all possible spanning tree of graph is mst;
// very easy we will find the connected component sum of edges weight for do so we first sort the edges by weight
// and then use dsu -> first check find(u)!=find(v) then do union and add the weight to answer;
// if(find(u)==find(v)) then edges can be removed no need to add hence by using dsu we can find mst
// mst-> edge weight less due to sorting and one connected component have n nodes and n-1 edges ad aall nodes are reachable from each other using the concept of dsu;;


// Prim's for msT-> 
// steps->
//1. Start with any node (say node 0)
//2. Keep a min-heap to pick the edge with minimum weight that connects to the unvisited node
//3. Mark nodes as visited once included in MST
//4. Add its adjacent edges to the min-heap
//5. Repeat until all nodes are visited

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
class Solution{
    public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return parent[i];
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }
        else{
            rank[parent_x]++;
            parent[parent_y]=parent_x;
        }
    }
    static bool comp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    int mstByKruskals(int n,vector<vector<int>>& edges){
        // not necesaay connected
        int m=edges.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        sort(edges.begin(),edges.end(),comp);
        int ans=0;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            if(find(u)!=find(v)){
                ans=ans+wt;
                Union(u,v);
            }
        }
        return ans;
    }
    int mstByPrims(int n,vector<vector<int>>& edges){
        // prims need conectd graph;
        int m=edges.size();
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        vector<bool> visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        // visited[0]=true; wrong;
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            if(visited[node]) continue;
            visited[node]=true;
            int wt=it.first;
            ans=ans+wt;
            for(auto nbr:adjList[node]){
                if(!visited[nbr.first]){
                    // visited[nbr.first]=true; wrong;
                    pq.push({nbr.second,nbr.first});
                }
            }
        }
        return ans;
    }
};



