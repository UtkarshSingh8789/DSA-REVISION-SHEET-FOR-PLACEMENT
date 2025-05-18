#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[5001][4][4][4];
    int n;
    int MOD=1e9+7;
    int solve(int i,int r,int y,int g){
        if(i>=n) return 1;
        if(dp[i][r][y][g]!=-1) return dp[i][r][y][g];
        int ans=0;
        for(int j=1;j<=3;j++){
            if(j==r) continue;
            for(int k=1;k<=3;k++){
                if(k==y || k==j) continue;
                for(int l=1;l<=3;l++){
                    if(l==g || l==k) continue;
                    ans=(ans+solve(i+1,j,k,l)%MOD)%MOD;
                }
            }
        }
        return dp[i][r][y][g]=ans%MOD;
    }
    int numOfWays(int n1) {
        n=n1;
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,0)%MOD;
        return ans;
    }
};