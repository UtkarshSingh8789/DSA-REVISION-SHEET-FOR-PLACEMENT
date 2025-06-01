#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION

class Solution {
public:
    int m,n;
    int dp[501][501];
    int solve(int i,int j,string& s1,string& s2){
        if(j>=n) return m-i;
        if(i>=m) return n-j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(i+1,j+1,s1,s2);
        }
        else{
            int insert=1+solve(i,j+1,s1,s2);
            int del=1+solve(i+1,j,s1,s2);
            int replace=1+solve(i+1,j+1,s1,s2);
            return dp[i][j]=min({insert,del,replace});
        }
    }
    int minDistance(string word1, string word2){
        m=word1.length();
        n=word2.length();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,word1,word2);
        return ans;
    }
};

//TABULATION

class Solution {
public:
    int m,n;
    int minDistance(string word1, string word2){
        m=word1.length();
        n=word2.length();
        int dp[501][501];
        for(int i=0;i<=m;i++){
            dp[i][n]=m-i;
        }
        for(int j=0;j<=n;j++){
            dp[m][j]=n-j;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    int insert=1+dp[i][j+1];
                    int del=1+dp[i+1][j];
                    int replace=1+dp[i+1][j+1];
                    dp[i][j]=min({insert,del,replace});
                }
            }
        }
        return dp[0][0];
    }
};

//SPACE OPTIMIZATION

class Solution {
public:
    int m,n;
    int minDistance(string word1, string word2){
        m=word1.length();
        n=word2.length();
        vector<int> next(n+1,0), curr(n+1,0);
        for(int j=0;j<=n;j++){
            next[j]=n-j;
        }
        for(int i=m-1;i>=0;i--){
            curr[n]=m-i;
            for(int j=n-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    curr[j]=next[j+1];
                }
                else{
                    int insert=1+curr[j+1];
                    int del=1+next[j];
                    int replace=1+next[j+1];
                    curr[j]=min({insert,del,replace});
                }
            }
            next=curr;
        }
        return next[0];
    }
};



