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
// for every index -> we create a graph and then use the concept of mst; jb bhi minimum puchhe aur graph connect krna ho taaki sare nods ek dusre se visi ho to ye sochna;
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
        if(rank[parent_x]==rank[parent_y]){
            rank[parent_x]++;
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else{
            parent[parent_x]=parent_y;
        }
    }
    static bool comp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int w=abs(x1-x2)+abs(y1-y2);
                edges.push_back({i,j,w});
            }
        }
        int m=edges.size();
        sort(edges.begin(),edges.end(),comp);
        int ans=0;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(find(u)!=find(v)){
                Union(u,v);
                ans=ans+w;
            }
        }
        return ans;
    }
};