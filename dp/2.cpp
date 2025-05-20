#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    int solve(int i,int j,vector<int>& nums,vector<int>& mul){
        if(i>=n) return 0;
        if(dp[i][j]!=-1e9) return dp[i][j];
        int start=nums[j]*mul[i]+solve(i+1,j+1,nums,mul);
        int end=nums[(m-1)-(i-j)]*mul[i]+solve(i+1,j,nums,mul);
        return dp[i][j]=max(start,end);
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        m=nums.size();
        n=mul.size();
        dp.resize(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int start=nums[j]*mul[i]+dp[i+1][j+1];
                int end=nums[(m-1)-(i-j)]*mul[i]+dp[i+1][j];
                dp[i][j]=max(start,end);
            }
        }
        return dp[0][0];
        // int ans=solve(0,0,nums,mul);
        // return ans;
    }
};

//MEMOIZATION;
// class Solution {
// public:
//     vector<vector<int>> dp;
//     int n,m;
//     int solve(int i,int j,vector<int>& nums,vector<int>& mul){
//         if(i>=n) return 0;
//         if(dp[i][j]!=-1e9) return dp[i][j];
//         int start=nums[j]*mul[i]+solve(i+1,j+1,nums,mul);
//         int end=nums[(m-1)-(i-j)]*mul[i]+solve(i+1,j,nums,mul);
//         return dp[i][j]=max(start,end);
//     }
//     int maximumScore(vector<int>& nums, vector<int>& mul) {
//         m=nums.size();
//         n=mul.size();
//         dp.resize(n+1,vector<int>(n+1,-1e9));
//         int ans=solve(0,0,nums,mul);
//         return ans;
//     }
// };