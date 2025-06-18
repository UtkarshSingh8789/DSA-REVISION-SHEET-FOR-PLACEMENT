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

// 5.cpp and 6.cpp same concept;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adjList;
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<set<int>> vec(n);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nbr:adjList[node]){
                vec[nbr].insert(node);
                for(int anc:vec[node]){
                    vec[nbr].insert(anc);
                }
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            for(int x:vec[i]){
                ans[i].push_back(x);
            }
        }
        return ans;
    }
};