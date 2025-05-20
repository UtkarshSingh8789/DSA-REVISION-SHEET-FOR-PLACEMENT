#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[100001][2];
    // int n;
    // int solve(int i,int pre,string& s){
    //     if(i>=n) return 0;
    //     if(dp[i][pre]!=-1) return dp[i][pre];
    //     int flip=1e9;
    //     int not_flip=1e9;
    //     if(pre==0){
    //         if((s[i]-'0')==0){
    //             not_flip=solve(i+1,0,s);
    //             flip=1+solve(i+1,1,s);
    //         }
    //         if((s[i]-'0')==1){
    //             not_flip=solve(i+1,1,s);
    //             flip=1+solve(i+1,0,s);
    //         }
    //     }
    //     else{
    //         if((s[i]-'0')==0){
    //             flip=1+solve(i+1,1,s);
    //         }
    //         else{
    //             not_flip=solve(i+1,1,s);
    //         }
    //     }
    //     return dp[i][pre]=min(flip,not_flip);
    // }
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        // memset(dp,-1,sizeof(dp));
        // int ans=solve(0,0,s);
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int flip=1e9;
                int not_flip=1e9;
                if(j==0){
                    if((s[i]-'0')==0){
                        not_flip=dp[i+1][0];
                        flip=1+dp[i+1][1];
                    }
                    else{
                        not_flip=dp[i+1][1];
                        flip=1+dp[i+1][0];
                    }
                }
                else{
                    if((s[i]-'0')==0){
                        flip=1+dp[i+1][1];
                        }
                    else{
                        not_flip=dp[i+1][1];
                    }
                }
                dp[i][j]=min(flip,not_flip);
            }
        }
        return dp[0][0];
    }
};