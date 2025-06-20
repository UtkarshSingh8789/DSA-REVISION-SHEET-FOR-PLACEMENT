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
    const int MOD=1e9+7;
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1;
        int x=i;
        int y=j;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                if(grid[new_x][new_y]>grid[x][y]){
                    ans=(ans+(dfs(new_x,new_y,grid,dp))%MOD)%MOD;
                }
            }
        }
        return dp[i][j]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // dp[i][j]=number of increasing path starting from i,j
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=(ans+(dfs(i,j,grid,dp))%MOD)%MOD;
            }
        }
        return ans;
    }
};