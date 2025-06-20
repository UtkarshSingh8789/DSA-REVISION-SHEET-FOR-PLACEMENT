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

// DP+DFS;
class Solution {
public:
    int dp[201][201];
    int m,n;
    int dfs(int i,int j,vector<vector<int>>& matrix){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        int x=i;
        int y=j;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int new_x=x+dx[k];
            int new_y=y+dy[k];
            if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                if(matrix[new_x][new_y]>matrix[x][y]){
                    ans=max(ans,1+dfs(new_x,new_y,matrix));
                }
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int maxi=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ans=dfs(i,j,matrix);
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};