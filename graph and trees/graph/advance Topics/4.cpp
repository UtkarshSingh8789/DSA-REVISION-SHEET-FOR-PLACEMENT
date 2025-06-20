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
    unordered_map<int,vector<int>> adjList;
    vector<int> count;// it stores the number of nodes rooted at ith node;
    int sum=0;// to store the sum of disctances from source node 0 to all other nodes;
    int N;
    int dfs(int src,int parent,int cnt){
        sum=sum+cnt;
        int ans=1;
        for(auto nbr:adjList[src]){
            if(nbr!=parent){
                ans=ans+dfs(nbr,src,cnt+1);
            }
        }
        count[src]=ans;
        return ans;
    }
    void dfs1(int src,int parent,vector<int>& vec){
        for(auto nbr:adjList[src]){
            if(nbr!=parent){
                vec[nbr]=vec[src]-count[nbr]+N-count[nbr];
                dfs1(nbr,src,vec);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        N=n;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        count.resize(n);
        dfs(0,-1,0);
        vector<int> vec(n);
        vec[0]=sum;
        dfs1(0,-1,vec);
        return vec;
    }
};