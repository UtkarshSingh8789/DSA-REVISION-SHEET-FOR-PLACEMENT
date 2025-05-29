#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    long long solve(int ele,vector<int>& nums,vector<int>& cost){
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(abs(nums[i]-ele))*(long long)(cost[i]);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        n=nums.size();
        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());
        long long ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            long long find1=solve(mid,nums,cost);
            long long find2=solve(mid+1,nums,cost);
            ans=min(find1,find2);
            if(find2>find1){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};