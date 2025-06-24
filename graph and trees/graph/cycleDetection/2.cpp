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

// vvi-> the nodes of cycle have same answer because from each node of cycle we can visited the same node 
// hence do toposort and find the nodes which cannot be start of cycle by making it visited then for remainning nodes find the length of
// cycle and save the answer of this nodes in dp and then perform dfs using precomuted dp to solve for remaining;
class Solution {
public:
    vector<int> dp;
    int dfs(int node,vector<int>& edges){
        if(dp[node]>0) return dp[node];
        dp[node]=1+dfs(edges[node],edges);
        return dp[node];
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            indegree[edges[i]]++;
        }
        queue<int> q;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                visited[i]=true;
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            int next=edges[node];
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
                visited[next]=true;
            }
        }
        dp.resize(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int cur=i;
                vector<int> cycle;
                while(!visited[cur]){
                    visited[cur]=true;
                    cycle.push_back(cur);
                    cur=edges[cur];
                }
                int len=cycle.size();
                for(auto node:cycle){
                    dp[node]=len;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]==0){
                dfs(i,edges);
            }
        }
        return dp;
    }
};