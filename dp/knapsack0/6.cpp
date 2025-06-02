#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION

class Solution {
public:
    int dp[101][101][101];
    int m;
    const int MOD=1e9+7;
    int solve(int i,int j,int k,vector<int>& group, vector<int>& profit){
        if(j<0) return 0;
        if(i>=m){
            if(k>0) return 0;
            return 1;
        }
        if(dp[i][j][max(0,k)]!=-1) return dp[i][j][k];
        int not_take=solve(i+1,j,k,group,profit);
        int take=0;
        if(j>=group[i]){
            take=solve(i+1,j-group[i],max(0,k-profit[i]),group,profit);
        }
        return dp[i][j][max(0,k)]=(take+not_take)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        m=group.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,n,minProfit,group,profit);
        return ans;
    }
};

//TABULATION

class Solution {
public:
    const int MOD=1e9+7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,0)));
        for(int j=0;j<=n;j++){
            dp[m][j][0]=1;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=minProfit;k++){
                    int not_take=dp[i+1][j][k];
                    int take=0;
                    if(j>=group[i]){
                        take=dp[i+1][j-group[i]][max(0,k-profit[i])];
                    }
                    dp[i][j][k]=(take+not_take)%MOD;
                }
            }
        }
        return dp[0][n][minProfit];
    }
};