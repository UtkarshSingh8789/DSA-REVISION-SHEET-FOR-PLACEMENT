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
//when neigbour has an apple or the answer of neightbou is non zero mean there is apple its subtree then add+2 to ansers of neigbour;
class Solution {
public:
    unordered_map<int,vector<int>> adjList;
    unordered_map<int,bool> visited;
    int dfs(int src,vector<bool>& vec){
        visited[src]=true;
        int ans=0;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                int val=dfs(nbr,vec);
                if(val>0 || vec[nbr]==true){
                    ans=ans+val+2;
                }
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int ans=dfs(0,hasApple);
        return ans;
    }
};