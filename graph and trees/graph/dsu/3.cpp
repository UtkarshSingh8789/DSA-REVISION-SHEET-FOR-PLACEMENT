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
// total number of pairs minus total number of pairs in conected component;
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(parent[i]==i) return i;
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        long long ans=((long long)(n)*(long long)(n-1))/2;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            Union(u,v);
        }
        unordered_map<int,int> umpp;
        for(int i=0;i<n;i++){
            int ele=find(i);
            umpp[ele]++;
        }
        for(auto it:umpp){
            int count=it.second;
            long long ele=((long long)count*(long long)(count-1))/2;
            ans=ans-ele;
        }
        return ans;
    }
};