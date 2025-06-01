#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[501][501];
    int n;
    int solve(int i,int j,string& s,string& s1){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s1[j]){
            return dp[i][j]=1+solve(i+1,j+1,s,s1);
        }
        else{
            int first=solve(i,j+1,s,s1);
            int second=solve(i+1,j,s,s1);
            return dp[i][j]=max(first,second);
        }
    }
    int minInsertions(string s) {
        n=s.length();
        string s1=s;
        reverse(s1.begin(),s1.end());
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,s,s1);
        cout<<ans<<endl;
        return n-ans;
    }
};