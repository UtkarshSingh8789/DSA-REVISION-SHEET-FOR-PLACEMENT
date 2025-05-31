#include<bits/stdc++.h>
using namespace std;
// we can do optimization in this we can convert 4d dp into 3d dp;
// because both moving simulatenously and at any point total steps by both of them is equal hence i+j=k+l;
// from here l=i+j-k;
class Solution {
public:
    int dp[51][51][51][51];
    int m;
    int n;
    int solve(int i,int j,int k,int l,vector<vector<int>>& grid){
        if(i>=m || k>=m || j>=n || l>=n || grid[i][j]==-1 || grid[k][l]==-1) return -1e9;
        if(i==(m-1) && j==(n-1)) return grid[i][j];
        if(k==(m-1) && l==(n-1)) return grid[k][l];
        if(dp[i][j][k][l]!=-1) return dp[i][j][k][l];
        int ans=grid[i][j];
        if(k!=i || l!=j)  ans=ans+grid[k][l];
        ans=ans+max({solve(i+1,j,k+1,l,grid),solve(i+1,j,k,l+1,grid),solve(i,j+1,k+1,l,grid),solve(i,j+1,k,l+1,grid)});
        return dp[i][j][k][l]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,0,grid);
        if(ans<=0) return 0;
        return ans;
    }
};
// optimized 3d;
class Solution {
public:
    int m, n;
    int dp[51][51][51];

    int solve(int i, int j, int k, vector<vector<int>>& grid) {
        int l = i + j - k;  // compute second person's column

        if (i >= m || j >= n || k >= m || l >= n || grid[i][j] == -1 || grid[k][l] == -1)
            return -1e9;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int res = grid[i][j];
        if (i != k || j != l)
            res += grid[k][l];

        int temp = max({
            solve(i + 1, j, k + 1, grid),
            solve(i + 1, j, k, grid),
            solve(i, j + 1, k + 1, grid),
            solve(i, j + 1, k, grid)
        });

        res += temp;
        return dp[i][j][k] = res;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, grid);
        return max(0, ans);
    }
};
