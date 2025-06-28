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

// DISJOINT SET -> it is used when every time graph is changing and connceting and at any instant someone ask to tell this belogs to component or not then use dsu you can answer it in 0(1) time;
// dsu-> graph changing-> connectinf-> asking about component think about dsu;
// example- > (1,2) -> union(1,2) -> find-> 1 , (2,3) -> union(2,4) -> find-> 1 suppose new edges come (4,5) someone ask does it belong to same component?
// no because find(4)=4 and find(5)=5 no -> you answered it in constant time.

// code snipet of dsu:

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
    }//t.c -> O(alpha(N)) where alpha=Inverse Ackermann function;
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
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]); // path compression; -> visualize striver video;
        // i am storing it so in future if some other node ask about its parent then it immediately give like dp;
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y) return;
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
            // ranks tells us about which guy is bigger..
            // smaller node is always connected to larger -> ?
            // if we connect lareger guy into smaller then for visiting some node we to travel more distance;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected){
        int n=isConnected.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    Union(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                count++;
            }
        }
        return count;
    }
};