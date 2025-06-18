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


// i make wrong in this basically for every node having indegree zero i find max and then do similar toposort;
// wrong approch;

// right approch like dp;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m=relations.size();
        unordered_map<int,vector<int>> adjList;
        vector<int> indegree(n,0);
        for(int i=0;i<m;i++){
            int u=relations[i][0]-1;
            int v=relations[i][1]-1;
            adjList[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i]=time[i];
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nbr:adjList[node]){
                dp[nbr]=max(dp[nbr],dp[node]+time[nbr]);
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};