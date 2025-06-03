#include<bits/stdc++.h>
using namespace std;

// LIS USING BINARY SEARCH;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                auto it=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[it]=nums[i];
            }
        }
        int ans=temp.size();
        return ans;
    }
};

// PRINTING LIS

vector<int> getLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);         
    vector<int> prev(n, -1); 
    int maxLen = 1, lastIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    // Reconstruct LIS
    vector<int> lis;
    for (int i = lastIndex; i != -1; i = prev[i]) {
        lis.push_back(nums[i]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

// COUNTING LIS

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            int ele=nums[i];
            for(int j=0;j<=i;j++){
                if(ele>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(ele>nums[j] && dp[i]==dp[j]+1){
                    count[i]=count[i]+count[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans=ans+count[i];
            }
        }
        return ans;
    }
};

