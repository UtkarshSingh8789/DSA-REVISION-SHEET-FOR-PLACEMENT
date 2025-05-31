#include<bits/stdc++.h>
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