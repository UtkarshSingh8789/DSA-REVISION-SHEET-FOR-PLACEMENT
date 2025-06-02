#include<bits/stdc++.h>
using namespace std;

// FOLLOW UP QUESTION FOR HOUSER ROBBER 3;

class Solution {
public:
    int solve(int i,int j,vector<int>& slices,vector<vector<int>>& dp){
        if(j==0) return 0;
        if(i>=slices.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int not_take=solve(i+1,j,slices,dp);
        int take=slices[i]+solve(i+2,j-1,slices,dp);
        return dp[i][j]=max(take,not_take);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        int k=n/3;
        vector<int> vec1={slices.begin(),slices.end()-1};
        int n1=vec1.size();
        vector<vector<int>> dp1(n1,vector<int>(k+1,-1));
        int ans1=solve(0,k,vec1,dp1);
        vector<int> vec2={slices.begin()+1,slices.end()};
        int n2=vec2.size();
        vector<vector<int>> dp2(n2,vector<int>(k+1,-1));
        int ans2=solve(0,k,vec2,dp2);
        return max(ans1,ans2);
    }
};