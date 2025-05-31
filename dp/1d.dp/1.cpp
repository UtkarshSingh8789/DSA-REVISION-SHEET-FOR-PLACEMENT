#include<bits/stdc++.h>
using namespace std;
// memoization;
class Solution {
public:
int solve(int i,int n,vector<int>& nums,vector<int>& dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int not_take=solve(i+1,n,nums,dp);
    int take=nums[i]+solve(i+2,n,nums,dp);
    return dp[i]=max(take,not_take);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n,-1);
        int ans1=solve(1,n,nums,dp1);
        vector<int> dp2(n-1,-1);
        int ans2=solve(0,n-1,nums,dp2);
        return max(ans1,ans2);
    }
};
// space optimization
class Solution {
public:
    int helper(int start,int end,vector<int>& nums){
        int prev1=nums[end];
        int prev2=0;
        for(int i=end-1;i>=start;i--){
            int not_take=prev1;
            int take=nums[i];
            if(i<end-1){
                take=take+prev2;
            }
            int curr=max(not_take,take);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans1=helper(1,n-1,nums);
        int ans2=helper(0,n-2,nums);
        return max(ans1,ans2);
    }
};
