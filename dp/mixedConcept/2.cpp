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
// the maintoughness of the question is finding the preffix arrray only
// pre[i][j]=total number of apples from (i,j) to the bottom right end(m-1,n-1) of matrix;
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> pre;
    int dp[51][51][11];
    const int MOD=1e9+7;
    int solve(int i,int j,int k){
        if(k==1){
            // kyuki cut humlog tbhi krrhe hai jb niche wala valid ho;
            return 1;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        // hporizontalCut;
        int ans=0;
        for(int row=i+1;row<m;row++){
            int totalTillEnd=pre[i][j];
            int loweerTillEnd=pre[row][j];
            int upperPart=totalTillEnd-loweerTillEnd;
            int lowerPart=loweerTillEnd;
            if(upperPart>=1 && lowerPart>=k-1){
                ans=(ans+solve(row,j,k-1)%MOD)%MOD;
            }
        }
        // verticalCut;
        for(int col=j+1;col<n;col++){
            int totalTillEnd=pre[i][j];
            int rightTillEnd=pre[i][col];
            int leftPart=totalTillEnd-rightTillEnd;
            int rightPart=rightTillEnd;
            if(leftPart>=1 && rightPart>=k-1){
                ans=(ans+solve(i,col,k-1)%MOD)%MOD;
            }
        }
        return dp[i][j][k]=ans%MOD;
    }
    int ways(vector<string>& pizza, int k) {
        m=pizza.size();
        n=pizza[0].size();
        pre.resize(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                pre[i][j]=pre[i][j+1];
                for(int l=i;l<m;l++){
                    if(pizza[l][j]=='A'){
                        pre[i][j]++;
                    }
                }
            }
        }
        if(pre[0][0]<k) return 0;
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,k)%MOD;
        return ans;
    }
};