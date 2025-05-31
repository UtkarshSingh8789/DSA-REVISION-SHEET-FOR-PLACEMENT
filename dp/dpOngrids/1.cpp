#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION

class Solution {
public:
    int dp[101][101];
    int m;
    int n;
    int solve(int i,int j,vector<vector<int>>& mat){
        if(i==(m-1) && j==(n-1)) return 1;
        if(i>=m || i<0 || j>=n || j<0) return 0;
        if(mat[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(i,j+1,mat);
        int down=solve(i+1,j,mat);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        if(mat[m-1][n-1]) return 0;
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,mat);
        return ans;
    }
};

//TABULATION

class Solution {
public:
    const int MOD=1e9+7;
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[m-1][n-1]==1 || grid[0][0]==1) return 0;
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1) continue;
                if(i==m-1 && j==n-1) continue;
                long long right=0;
                if(j+1<n && grid[i][j]==0){
                    right=dp[i][j+1];
                }
                long long down=0;
                if(i+1<m && grid[i][j]==0){
                    down=dp[i+1][j];
                }
                dp[i][j]=(right+down);
            }
        }
        return dp[0][0];
    }
};

//SPACE OPTIMIZATION

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[m-1][n-1]==1 || grid[0][0]==1) return 0;
        vector<long long> curr(n,0);
        vector<long long> prev(n,0);
        prev[n-1]=1;
        for(int i=(m-1);i>=0;i--){
            for(int j=(n-1);j>=0;j--){
                if(grid[i][j]==1){
                    curr[j]=0;
                    continue;
                }
                long long right=0;
                if(j+1<n){
                    right=curr[j+1];
                }
                long long down=prev[j];
                curr[j]=right+down;
            }
            prev=curr;
        }
        return prev[0];
    }
};