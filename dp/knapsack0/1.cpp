#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION

class Solution {
public:
int solve(int i,int j,vector<vector<int>>& dp,vector<int>& nums){
    if(i>=nums.size()){
        if(j==0) return 1;
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int not_take=solve(i+1,j,dp,nums);
    int take=0;
    if(j>=nums[i]){
        take=solve(i+1,j-nums[i],dp,nums);
    }
    return dp[i][j]=not_take+take;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum+target)%2!=0 || (sum+target)<0) {
            return 0;
        }
        int tar=(sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        int ans=solve(0,tar,dp,nums);
        return ans;
    }
};

//TABULATION

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum+target)%2!=0 || (sum+target)<0) {
            return 0;
        }
        int tar=(sum+target)/2;
        vector<vector<int>> dp(n+1,vector<int>(tar+1,0));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=tar;j++){
                int not_take=dp[i+1][j];
                int take=0;
                if(j>=nums[i]){
                    take=dp[i+1][j-nums[i]];
                }
                dp[i][j]=not_take+take;
            }
        }
        return dp[0][tar];
    }
};

//SPACE OPTIMIZATION

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum+target)%2!=0 || (sum+target)<0) {
            return 0;
        }
        int tar=(sum+target)/2;
        vector<int> curr(tar+1,0);
        vector<int> prev(tar+1,0);
        prev[0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=tar;j++){
                int not_take=prev[j];
                int take=0;
                if(j>=nums[i]){
                    take=prev[j-nums[i]];
                }
                curr[j]=not_take+take;
            }
            prev=curr;
        }
        return prev[tar];
    }
};