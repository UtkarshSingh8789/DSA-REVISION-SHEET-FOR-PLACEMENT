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

// vvi question ->

// for every zero we will count its neight component size;
// if the sameparent means neigbours in same component to handle this edge case we use set;
class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;// union by rank
    vector<int> size;// union by size;
    // dono me se koi ek hi use hota hai;
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionByRank(int x,int y){
        int parent_x=findPar(x);
        int parent_y=findPar(y);
        if(parent_x==parent_y) return;
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
    void unionBySize(int x,int y){
        int parent_x=findPar(x);
        int parent_y=findPar(y);
        if(parent_x==parent_y) return;
        if(size[parent_x]>=size[parent_y]){
            parent[parent_y]=parent_x;
            size[parent_x]+=size[parent_y];
        }
        else{
            parent[parent_x]=parent_y;
            size[parent_y]+=size[parent_x];
        }
    }
};

class Solution {
public:
    bool isValid(int x,int y,int m,int n){
        return x>=0 && y>=0 && x<m && y<n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        DisjointSet ds(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int x=i;
                    int y=j;
                    int dx[]={-1,0,1,0};
                    int dy[]={0,1,0,-1};
                    for(int k=0;k<4;k++){
                        int new_x=x+dx[k];
                        int new_y=y+dy[k];
                        if(isValid(new_x,new_y,m,n) && grid[new_x][new_y]==1){
                            int numNode=n*x+y;
                            int numNbr=new_x*n+new_y;
                            if(ds.findPar(numNode)!=ds.findPar(numNbr)){
                                ds.unionBySize(numNode,numNbr);
                            }
                        }
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int ans=0;
                    int x=i;
                    int y=j;
                    int dx[]={-1,0,1,0};
                    int dy[]={0,1,0,-1};
                    unordered_set<int> st;
                    for(int k=0;k<4;k++){
                        int new_x=x+dx[k];
                        int new_y=y+dy[k];
                        if(isValid(new_x,new_y,m,n) && grid[new_x][new_y]==1){
                            int index=n*new_x+new_y;
                            int parent=ds.findPar(index);
                            if(st.find(parent)==st.end()){
                                st.insert(parent);
                                ans=ans+ds.size[parent];
                            }
                        }
                    }
                    maxi=max(maxi,ans+1);
                }
            }
        }
        if(maxi==0){
            return m*n;
        }
        return maxi;
    }
};
