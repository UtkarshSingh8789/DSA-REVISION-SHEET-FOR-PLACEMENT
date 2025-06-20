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
using namespace std;

// VISUALISE DP ON GRAPH
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int m=edges.size();
        int n=colors.size();
        vector<int> indegree(n,0);
        unordered_map<int,vector<int>> adjList;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<vector<int>> dp(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i][colors[i]-'a']++;
            }
        }
        int count=0;
        int maxi=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto nbr:adjList[node]){
                for(int c=0;c<26;c++){
                    int inc=0;
                    if(colors[nbr]-'a'==c){
                        inc=1;
                    }
                    dp[nbr][c]=max(dp[nbr][c],dp[node][c]+inc);
                }
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
            maxi=max(maxi,*max_element(dp[node].begin(),dp[node].end()));
        }
        if(count==n){
            return maxi;
        }
        return -1;
    }
};