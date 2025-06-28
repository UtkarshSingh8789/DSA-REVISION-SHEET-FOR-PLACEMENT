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

//NUMBER OF ISLAND->2;
// example -> n=4,m=5
// queries=[[0,0],[0,0],[1,1],[1,0],[0,1],[0,3],[1,3],[0,4],[3,2],[2,2],[1,2],[0,2]];

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findPar(int i){
        if(parent[i]==i) return i;
        return parent[i]=findPar(parent[i]);
    }
    void unionByRank(int x,int y){
        int parent_x=findPar(x);
        int parent_y=findPar(y);
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }
        else{
            rank[parent_x]++;
            parent[parent_y]=parent_x;
        }
    }
}; // Class of DisjointSet;
class Solution{
    private:
    bool isSafe(int u,int v,int n,int m){
        if(u>=n || u<0 || v>=m || v<0) return false;
        return true;
    }
    public:
    vector<int> numOfIslands(int n,int m,vector<vector<int>>& queries){
        int q=queries.size();
        DisjointSet ds(n*m);
        vector<vector<int>> grid(n,vector<int>(m,0));// initally all water;
        int count=0;
        vector<int> ans;
        for(int i=0;i<q;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(grid[u][v]==1){
                ans.push_back(count);
                continue;
            }
            grid[u][v]=1;
            count++;
            // check the neighbour;
            int du[]={-1,0,1,0};
            int dv[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_u=u+du[i];
                int new_v=v+dv[i];
                if(isSafe(u,v,n,m)){
                    if(grid[u][v]==1){
                        int nodeNumberInParent=u*m+v;
                        int adjNodeNumberInParent=new_u*m+new_v;
                        if(ds.findPar(nodeNumberInParent)!=ds.findPar(adjNodeNumberInParent)){
                            count--;
                            ds.unionByRank(nodeNumberInParent,adjNodeNumberInParent);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};