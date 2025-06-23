// THEORY -> for every node we have to tell the shortest path to every node it is helful in this case
// it is also useful for detecting negative cycles and  it is used in case of negative edges;
// in this build adjMatrix for graph;

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

class Solution{
    public:
    vector<vector<int>> floydWarshal(int n,vector<vector<int>> edges){
        int m=edges.size();
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) matrix[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            matrix[u][v]=w;
        }
        vector<vector<int>> dis=matrix;
        for(int k=0;k<n;k++){
            // k reprsent every possible intermediate node for min dis between i and j;
            // k must be outer loop -> if confusion check notes,or striver video or carefully observe-> if inner loop then we donont have precomputed value dis[i][k] and dis[k][j];
            // You must finish using one intermediate node (k) for all (i, j) pairs, before moving to the next one.
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]!=1e9 && dis[k][j]!=1e9){
                        dis[i][j]=min(dis[i][j],(dis[i][k]+dis[k][j]));
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][j]==1e9){
                    dis[i][j]=-1;
                }
            }
        }
        return dis;
    }
    bool detectNegativeCycle(vector<vector<int>>& dis){
        // After running Floyd-Warshall, if there exists any node i such that dist[i][i] < 0, 
        //it means there's a negative weight cycle in the graph that is reachable from node i.
        int n=dis.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][i]<0) return true;
            }
        }
        return false;
    }
};