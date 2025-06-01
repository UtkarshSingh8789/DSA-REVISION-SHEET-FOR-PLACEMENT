#include<bits/stdc++.h>
using namespace std;

// MEMOIZATION - O(N^3) we can optimize becau interleabe string index can be optained from first and second;

class Solution {
public:
    int dp[101][101][201];
    int n1,n2,m;

    bool solve(int i,int j,int k,string& s1,string& s2, string& s3){
        if(k>=m){
            if(i>=n1 && j>=n2) return true;
            return false;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        if(i<n1 && j<n2 && s1[i]==s3[k] && s2[j]==s3[k]){
            bool take1=solve(i+1,j,k+1,s1,s2,s3);
            bool take2=solve(i,j+1,k+1,s1,s2,s3);
            return dp[i][j][k]=take1 || take2;
        }
        else{
            if(i<n1 && s1[i]==s3[k]){
                return dp[i][j][k]=solve(i+1,j,k+1,s1,s2,s3);
            }
            else if(j<n2 && s2[j]==s3[k]){
                return dp[i][j][k]=solve(i,j+1,k+1,s1,s2,s3);
            }
        }
        return dp[i][j][k]=false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.length();
        n2=s2.length();
        m=s3.length();
        if((n1+n2)!=m) return false;
        memset(dp,-1,sizeof(dp));
        bool ans=solve(0,0,0,s1,s2,s3);
        return ans;
    }
};

// OPTIMIZED APPROCH;

class Solution {
public:
    int dp[101][101];
    int n1,n2,m;
    
    bool solve(int i,int j,string& s1,string& s2, string& s3){
        if(i>=n1 && j>=n2) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        int k=i+j;
        if(i<n1 && s1[i]==s3[k] && solve(i+1,j,s1,s2,s3)){
            return dp[i][j]=true;
        }
        if(j<n2 && s2[j]==s3[k] && solve(i,j+1,s1,s2,s3)){
            return dp[i][j]=true;
        }
        return dp[i][j]=false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.length();
        n2=s2.length();
        m=s3.length();
        if((n1+n2)!=m) return false;
        memset(dp,-1,sizeof(dp));
        bool ans=solve(0,0,s1,s2,s3);
        return ans;
    }
};