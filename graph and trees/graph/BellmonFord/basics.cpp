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

class Solution {
    public:
    vector<int> bellmon_Ford(int n,vector<vector<int>>& edges,int src){
        int m=edges.size();
        vector<int> dis(n,1e9);
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int w=edges[j][2];
                if(dis[u]!=1e9 && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;// we have to do realization for every edges n-1 times n-1 th time will decide about negative cycle;
                    //  edges can be in any order;
                }
            }
        }
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(dis[u]!=1e9 && dis[u]+w<dis[v]){
                return {-1};
            }
        }
        return dis;
    }
};