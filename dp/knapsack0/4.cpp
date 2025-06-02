#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int dp[100002][2];
    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2){
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]){
            int no_swap=solve(i+1,0,nums1,nums2);
            ans=min(ans,no_swap);
        }
        if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]){
            swap(nums1[i],nums2[i]);
            ans=min(ans,1+solve(i+1,1,nums1,nums2));
            swap(nums1[i],nums2[i]);
        }
        return dp[i][j]=ans;
    }   
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        vector<int> vec1;
        vec1.push_back(-1);
        for(int i=0;i<m;i++){
            vec1.push_back(nums1[i]);
        }
        vector<int> vec2;
        vec2.push_back(-1);
        for(int i=0;i<m;i++){
            vec2.push_back(nums2[i]);
        }
        n=vec2.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(1,0,vec1,vec2);
        return ans;
    }
};