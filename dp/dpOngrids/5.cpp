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
using namespace std;
// very intresting question;
class Solution {
public:
    vector<vector<pair<int,long long>>> dp;
    const int MOD=1e9+7;
    int n;
    pair<int,long long> p1={-1,-1ll};
    pair<int,long long> solve(int i,int j,vector<string>& board){
        if(i<0 || j<0 || board[i][j]=='X') return {-1e9,0};
        if(i==0 && j==0) return {0,1};
        if(dp[i][j]!=p1) return dp[i][j];
        int val=0;
        if(!(i==(n-1) && j==(n-1))) val=board[i][j]-'0';
        auto up=solve(i-1,j,board);
        auto left=solve(i,j-1,board);
        auto diag=solve(i-1,j-1,board);
        int ans=val+max({up.first,left.first,diag.first});
        long long count=0;
        if(val+up.first==ans){
            count=(count+up.second)%MOD;
        }
        if(val+left.first==ans){
            count=(count+left.second)%MOD;
        }
        if(val+diag.first==ans){
            count=(count+diag.second)%MOD;
        }
        return dp[i][j]={ans,count};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        dp.resize(n,vector<pair<int,long long>>(n,p1));
        pair<int,long long> p=solve(n-1,n-1,board);
        if(p.first<0) return {0,0};
        vector<int> ans;
        ans={p.first,(int)p.second};
        return ans;
    }
};
class Solution {
public:
    const int MOD=1e9+7;
    int m,n;
    vector<vector<int>> maxScore;
    vector<vector<int>> countPaths;

    int solve(int i,int j,vector<string>& board){
        if(i<0 || j<0 || board[i][j]=='X') return -1e9;
        if(i==0 && j==0){
            countPaths[i][j]=1;
            return 0;
        }
        if(maxScore[i][j]!=-1) return maxScore[i][j];
        int val=0;
        if(board[i][j]!='S' && board[i][j]!='E'){
            val=board[i][j]-'0';
        }
        int up=solve(i-1,j,board);
        int left=solve(i,j-1,board);
        int diag=solve(i-1,j-1,board);
        int maxi=max({up,left,diag});
        int count=0;
        if(up==maxi && up>=0) count=(count+countPaths[i-1][j])%MOD;
        if(left==maxi && left>=0) count=(count+countPaths[i][j-1])%MOD;
        if(diag==maxi && diag>=0) count=(count+countPaths[i-1][j-1])%MOD;
        maxScore[i][j]=maxi+val;
        countPaths[i][j]=count;
        return maxScore[i][j];
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        m=board.size();
        n=board[0].size();
        maxScore.assign(m,vector<int>(n,-1));
        countPaths.assign(m,vector<int>(n,0));
        int ans=solve(m-1,n-1,board);
        if(ans<0) return {0,0};
        return {ans,countPaths[m-1][n-1]};
    }
};