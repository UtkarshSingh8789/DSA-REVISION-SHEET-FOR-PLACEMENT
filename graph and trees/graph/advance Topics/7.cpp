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

// DP+DFS;
class Solution {
public:
    int dp[501];
    int dfs(int i,unordered_map<int,vector<int>>& adjList,vector<int>& quiet){
        if(dp[i]!=-1) return dp[i];
        int minPerson=i;
        for(auto nbr:adjList[i]){
            int person=dfs(nbr,adjList,quiet);
            if(quiet[person]<quiet[minPerson]){
                minPerson=person;
            }
        }
        return dp[i]=minPerson;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        int m=richer.size();
        unordered_map<int,vector<int>> adjList;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            int u=richer[i][0];
            int v=richer[i][1];
            adjList[v].push_back(u);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int answer=dfs(i,adjList,quiet);
            ans[i]=answer;
        }
        return ans;
    }
};