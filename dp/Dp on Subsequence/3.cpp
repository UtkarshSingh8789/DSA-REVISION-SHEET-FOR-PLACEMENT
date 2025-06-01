#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--) {
                if(str1[i]==str2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                } else {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int i=0;
        int j=0;
        string s="";
        while(i<m && j<n){
            if(str1[i]==str2[j]){
                s=s+str1[i];
                i++;
                j++;
            }
            else{
                if(dp[i+1][j]>=dp[i][j+1]){
                    s=s+str1[i];
                    i++;
                }
                else{
                    s=s+str2[j];
                    j++;
                }
            }
        }
        while(i<m){
            s=s+str1[i];
            i++;
        }
        while(j<n){
            s=s+str2[j];
            j++;
        }
        return s;
    }
};