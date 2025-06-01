#include<bits/stdc++.h>
using namespace std;

// MEMOIZATION;

class Solution {
public:
    int dp[501][501];
    int n1,n2;
    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2){
        if(i>=n1 || j>=n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2);
        int not_take=solve(i,j+1,nums1,nums2);
        int not_take1=solve(i+1,j,nums1,nums2);
        int not_take2=solve(i+1,j+1,nums1,nums2);
        return dp[i][j]=max({take,not_take,not_take1,not_take2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1.size();
        n2=nums2.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,nums1,nums2);
        if(ans==0){
            int a=*max_element(nums1.begin(),nums1.end());
            int b=*min_element(nums2.begin(),nums2.end());
            int c=*max_element(nums2.begin(),nums2.end());
            int d=*min_element(nums1.begin(),nums1.end());
            return max(a*b,c*d);
        }
        return ans;
    }
};

//TABULATION

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int take=nums1[i]*nums2[j]+dp[i+1][j+1];
                int not_take=dp[i][j+1];
                int not_take1=dp[i+1][j];
                int not_take2=dp[i+1][j+1];
                dp[i][j]=max({take,not_take,not_take1,not_take2});
            }
        }
        int ans=dp[0][0];
        if(ans==0){
            int a=*max_element(nums1.begin(),nums1.end());
            int b=*min_element(nums2.begin(),nums2.end());
            int c=*max_element(nums2.begin(),nums2.end());
            int d=*min_element(nums1.begin(),nums1.end());
            return max(a*b,c*d);
        }
        return ans;
    }
};

//SPACE OPTIMIZATION

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> prev(n2+1,0);
        vector<int> curr(n2+1,0);
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int take=nums1[i]*nums2[j]+prev[j+1];
                int not_take=curr[j+1];
                int not_take1=prev[j];
                int not_take2=prev[j+1];
                curr[j]=max({take,not_take,not_take1,not_take2});
            }
            prev=curr;
        }
        int ans=prev[0];
        if(ans==0){
            int a=*max_element(nums1.begin(),nums1.end());
            int b=*min_element(nums2.begin(),nums2.end());
            int c=*max_element(nums2.begin(),nums2.end());
            int d=*min_element(nums1.begin(),nums1.end());
            return max(a*b,c*d);
        }
        return ans;
    }
};