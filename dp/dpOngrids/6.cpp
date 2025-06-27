#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int m,n;
    int dp[501][501][3];
    int solve(int i,int j,int k,vector<vector<int>>& grid){
        if(i>=m || j>=n) return -1e9;
        if(i==(m-1) && j==(n-1)){
            if(k<2 && grid[m-1][n-1]<0) return 0;
            else return grid[m-1][n-1];
        }
        if(dp[i][j][k]!=-1e9) return dp[i][j][k];
        int neutralize=-1e9;
        int take=-1e9; // if not neutralize means take the value;
        if(grid[i][j]<0 && k<2){
            int right=solve(i,j+1,k+1,grid);
            int down=solve(i+1,j,k+1,grid);
            neutralize=max(right,down);
        }
        int right=grid[i][j]+solve(i,j+1,k,grid);
        int down=grid[i][j]+solve(i+1,j,k,grid);
        take=max(right,down);
        return dp[i][j][k]=max(take,neutralize);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();
        n=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=-1e9;
                }
            }
        }
        int ans=solve(0,0,0,coins);
        return ans;
    }
};