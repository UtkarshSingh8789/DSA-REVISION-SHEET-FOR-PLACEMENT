#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> prev(n,-1);
        vector<int> dp(n,1);
        int maxi=1;
        int index=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    prev[i]=j;
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                index=i;
            }
        }
        vector<int> ans;
        while(index>=0){
            ans.push_back(nums[index]);
            index=prev[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};