#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION;

class Solution {
public:
int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    int n=triangle.size();
    if(i==n-1) return triangle[n-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down=solve(i+1,j,triangle,dp);
    int diagonal_right=solve(i+1,j+1,triangle,dp);
    return dp[i][j]=triangle[i][j]+min(down,diagonal_right);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=solve(0,0,triangle,dp);
        return ans;
    }
};

// tabulation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<triangle[n-1].size();j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=(n-2);i>=0;i--){
            for(int j=(triangle[i].size()-1);j>=0;j--){
                int ele=triangle[i][j];
                int down=1e9;
                if((i+1)<n){
                    down=dp[i+1][j];
                }
                int diagonal_right=1e9;
                if((i+1)<n && (j+1)<triangle[i+1].size()){
                    diagonal_right=dp[i+1][j+1];
                }
                dp[i][j]=ele+min(down,diagonal_right);
            }
        }
        return dp[0][0];
    }
};

// SPACE OPTIMIZATION

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(triangle[n-1]);  // base case: last row

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(triangle[i].size(), 0);
            for (int j = 0; j < triangle[i].size(); j++) {
                int down = prev[j];
                int diagonal_right = prev[j + 1];
                curr[j] = triangle[i][j] + min(down, diagonal_right);
            }
            prev = curr;
        }

        return prev[0];
    }
};
