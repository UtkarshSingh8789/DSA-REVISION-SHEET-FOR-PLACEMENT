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

// vvi question most conceptual since directed and atmost one directed edge from an node then do toposort and visited the nodes which cannot be the start of cyle then the remaining nodes find the longest cycle by considering unvisited nodes as start of nodes;
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        // jb bhi directed graph ho aur cycle ka baat kre toh jo node se cycle nhi bn skta we toposort se nikal jayega bcha hua node se cycle bn skta hai kyuki sare node cycle me ek barr present hongr diya hua hai.. hr ek node se nikal ke maximum nikaldenge;
        int n=edges.size();
        unordered_map<int,vector<int>> adjList;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            int u=i;
            int v=edges[i];
            if(v!=-1){
                adjList[u].push_back(v);
                indegree[v]++;
            }
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
            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(visited[i]==true) continue;
            int node=i;
            int len=0;
            while(!visited[node]){
                visited[node]=true;
                node=edges[node];
                len++;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};