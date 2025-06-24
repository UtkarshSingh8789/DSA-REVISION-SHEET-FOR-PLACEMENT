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
// class Solution {
// public:
//     void dfs(int src,unordered_map<int,list<int>>& adjList,unordered_map<int,bool>& visited){
//         visited[src]=true;
//         for(auto nbr:adjList[src]){
//             if(!visited[nbr]){
//                 dfs(nbr,adjList,visited);
//             }
//         }
//     }
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         int m=connections.size();
//         if(m<(n-1)) return -1;
//         unordered_map<int,list<int>> adjList;
//         unordered_map<int,bool> visited;
//         for(int i=0;i<m;i++){
//             int u=connections[i][0];
//             int v=connections[i][1];
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }
//         int count=0;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 dfs(i,adjList,visited);
//                 count++;
//             }
//         }
//         return count-1;
//     }
// };


class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
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
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count=n;
        int m=connections.size();
        if(m<(n-1)) return -1;
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<m;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(find(u)!=find(v)){
                Union(u,v);
                count--;
            }   
        }
        return count-1;
    }
};