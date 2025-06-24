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
        else {
            rank[parent_x]++;
            parent[parent_y]=parent_x;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<m;i++){
            int x=roads[i][0]-1;
            int y=roads[i][1]-1;
            Union(x,y);
        }
        int group=find(0);
        int ans=1e9;
        for(int i=0;i<m;i++){
            int x=roads[i][0]-1;
            int y=roads[i][1]-1;
            int w=roads[i][2];
            if(find(x)==group || find(y)==group){
                cout<<group<<endl;
                cout<<find(x)<<endl;
                cout<<find(y)<<endl;
                ans=min(ans,w);
            }
        }
        return ans;
    }
};