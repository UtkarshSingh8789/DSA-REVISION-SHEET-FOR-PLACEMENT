#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m;
    int n;
    bool comp(int i,int j,vector<string>& strs){
        for(int k=0;k<m;k++){
            if(strs[k][j]>strs[k][i]) return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        m=strs.size();
        n=strs[0].size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(comp(i,j,strs)){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=n-maxi;
        return ans;
    }
};