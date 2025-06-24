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
    vector<bool> visited;
    int n;

    void dfs(int src, vector<vector<int>>& stones){
        visited[src] = true;
        for(int i = 0; i < n; i++){
            if(!visited[i] && (stones[src][0] == stones[i][0] || stones[src][1] == stones[i][1])){
                dfs(i, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones){
        n = stones.size();
        visited.resize(n, false);
        int components = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, stones);
                components++;
            }
        }
        return n - components;
    }
};
