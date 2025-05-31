#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION

class Solution {
public:
    int dp[71][71][71];
    int m,n;
    int solve(int i,int j,int k,vector<vector<int>>& grid){
        if(i>=m || j>=n || j<0 || k>=n || k<0) return -1e9;
        if(i==(m-1)){
            if(j==k) return grid[i][j];
            return grid[i][j]+grid[i][k];
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=grid[i][j];
        if(j!=k) ans=ans+grid[i][k];
        int dx[]={-1,0,1};
        int maxi=-1e9;
        for(int l=0;l<3;l++){
            for(int r=0;r<3;r++){
                maxi=max(maxi,solve(i+1,j+dx[l],k+dx[r],grid));
            }
        }
        ans=ans+maxi;
        return dp[i][j][k]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,n-1,grid);
        return ans;
    }
};

//TABULATION

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(j==k){
                    dp[m-1][j][k]=grid[m-1][j];
                }
                else{
                    dp[m-1][j][k]=grid[m-1][j]+grid[m-1][k];
                }
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                for(int k=n-1;k>=0;k--){
                    int ans=grid[i][j];
                    if(j!=k) ans=ans+grid[i][k];
                    int dx[]={-1,0,1};
                    int maxi=-1e9;
                    for(int l=0;l<3;l++){
                        for(int p=0;p<3;p++){
                            int x=dx[l]+j;
                            int y=dx[p]+k;
                            if(x>=0 && x<n && y>=0 && y<n){
                                maxi=max(maxi,dp[i+1][x][y]);
                            }
                        }
                    }
                    ans=ans+maxi;
                    dp[i][j][k]=ans;
                }
            }
        }
        return dp[0][0][n-1];
    }
};