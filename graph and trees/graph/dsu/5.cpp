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
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
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
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            string s=equations[i];
            if(s[1]=='='){
                Union((s[0]-'a'),(s[3]-'a'));
            }
        }
        for(int i=0;i<n;i++){
            string s=equations[i];
            if(s[1]=='!'){
                int parent_x=find(s[0]-'a');
                int parent_y=find(s[3]-'a');
                if(parent_x==parent_y) return false;
            }
        }
        return true;
    }
};