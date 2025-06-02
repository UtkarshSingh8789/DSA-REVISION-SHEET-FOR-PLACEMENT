#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[1001][1001];
    int solve(int current,int len,int n){
        if(current==n) return 0;
        if(current>n) return 1e9;
        if(dp[current][len]!=-1) return dp[current][len];
        int copy_paste=2+solve(2*current,current,n);
        int paste=1+solve(current+len,len,n);
        return dp[current][len]=min(copy_paste,paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        if(n==2) return 2;
        memset(dp,-1,sizeof(dp));
        int ans=solve(2,1,n)+2;
        return ans;
    }
};