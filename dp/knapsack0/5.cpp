#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(int i,int j,vector<pair<int,int>>& vec,vector<vector<int>>& dp){
    if(i>=vec.size()) return 0;
    if(dp[i][j+1]!=-1) return dp[i][j+1];
    int not_take=helper(i+1,j,vec,dp);
    int take=0;
    if(j==-1 || vec[j].first==vec[i].first){
        take=vec[i].second+helper(i+1,i,vec,dp);
    }
    else if(vec[j].first<vec[i].first && vec[j].second<=vec[i].second){
        take=vec[i].second+helper(i+1,i,vec,dp);
    }
    return dp[i][j+1]=max(take,not_take);
}
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={ages[i],scores[i]};
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int ans=helper(0,-1,vec,dp);
        return ans;
    }
};