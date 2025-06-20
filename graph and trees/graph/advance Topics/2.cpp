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

// minimimu edge reversal so that for every node src node 0 is visited;
// what i will do first i will reverse all the edge so that i can think from src node and this edge reversal cost 0
// and make undirected graph from neighbour to sorce with cost 1 and then do bfs and solve;
class Solution {
public:
    unordered_map<int,list<pair<int,int>>> adjList;
    void dfs(int src,vector<bool>& visited,int& count){
        visited[src]=true;
        for(auto it:adjList[src]){
            if(!visited[it.first]){
                count=count+it.second;
                dfs(it.first,visited,count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        for(int i=0;i<m;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adjList[v].push_back({u,0});
            adjList[u].push_back({v,1});
        }
        int count=0;
        vector<bool> visited(n,false);
        dfs(0,visited,count);
        return count;
    }
};