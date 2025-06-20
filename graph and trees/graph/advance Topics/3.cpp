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


// RE-> ROOTING IN GRAPH;

class Solution {
public:
    int ele;
    vector<int> vec;
    unordered_map<int,vector<pair<int,int>>> adjList;
    vector<int> depth;
    vector<bool> visited;
    void dfs(int src,int d){
        visited[src]=true;
        depth[src]=d;
        for(auto nbr:adjList[src]){
            if(!visited[nbr.first]){
                ele=ele+nbr.second;
                vec[nbr.first]=vec[src]+nbr.second;
                dfs(nbr.first,d+1);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back({v,0});
            adjList[v].push_back({u,1});
        }
        vec.resize(n,0);// it will store that for source node 0 each remaining node is visited in how many edge reversal;
        depth.resize(n);// it stores the depth of every node from source node because it is necessary to store it so that we can calculate for other node -> 
        //suppose from 0 depth of any node let say 1 is 2 and from 0 one edge reversal is required to visit 1 which is stored in vec -> so from 1 to reach 0 is depth[1]-vec[1];
        visited.resize(n,false);
        dfs(0,0);
        vector<int> ans(n);
        ans[0]=ele;
        for(int i=1;i<n;i++){
            ans[i]=ans[0]+((depth[i]-vec[i])-vec[i]);
            // extra vec[i] is suptracting to av0id duplicacy we have to subtract the vec[1] because we have calculated in answer for node 0 to 1 and for node 1 to 1 is zero so one extra subtraction
        }
        return ans;
    }
};