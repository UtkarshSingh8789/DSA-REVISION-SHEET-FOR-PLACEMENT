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

// for neigbou we will nount how many neighbour are maxi and ans will be countofnbr-nbr having value maxi;
// similar Concept-> Make Cost of Paths Equal in a Binary Tree 2673;
class Solution {
public:
    unordered_map<int,vector<int>> adjList;
    unordered_map<int,bool> visited;
    int ans=0;
    long long dfs(int src,vector<int>& cost){
        visited[src]=true;
        long long maxi=0;
        long long maxi_cnt=0;
        long long count=0;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                long long val=dfs(nbr,cost);
                count++;
                if(val>maxi){
                    maxi=val;
                    maxi_cnt=1;
                }
                else if(val==maxi){
                    maxi_cnt++;
                }
            }
        }
        ans=ans+count-maxi_cnt;
        return 1LL*maxi+1LL*cost[src];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        dfs(0,cost);
        return ans;
    }
};