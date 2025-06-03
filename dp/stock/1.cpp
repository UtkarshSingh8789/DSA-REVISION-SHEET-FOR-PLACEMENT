#include<bits/stdc++.h>
using namespace std;

// MEMOIZATION 

class Solution {
public:
    int dp[1001][2][101];
    int n;
    int solve(int i,int j,int k,vector<int>& prices){
        if(k==0) return 0;
        if(i>=n) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=-1e9;
        if(j==0){
            int buy=-prices[i]+solve(i+1,1,k,prices);
            int not_buy=solve(i+1,j,k,prices);
            ans=max(ans,max(buy,not_buy));
        }
        else{
            int sell=prices[i]+solve(i+1,0,k-1,prices);
            int not_sell=solve(i+1,j,k,prices);
            ans=max(ans,max(sell,not_sell));
        }
        return dp[i][j][k]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,k,prices);
        return ans;
    }
};

// TABULATION

class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<=1;++j){
                for(int k=1;k<=K;++k){
                    if(j==0){
                        dp[i][j][k]=max(
                            -prices[i]+dp[i+1][1][k],
                            dp[i+1][0][k]
                        );
                    }else{
                        dp[i][j][k]=max(
                            prices[i]+dp[i+1][0][k-1],
                            dp[i+1][1][k]
                        );
                    }
                }
            }
        }
        return dp[0][0][K];
    }
};