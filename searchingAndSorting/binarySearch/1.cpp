// The distance of a pair of integers a and b is defined as the absolute difference between a and b.
// Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

// Input: nums = [1,3,1], k = 1
// Output: 0
// Explanation: Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int findCount(int ele,vector<int>& nums){
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            while(i<j && (nums[j]-nums[i])>ele){
                i++;
            }
            count=count+(j-i);
            j++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums[n-1]-nums[0];
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            int count=findCount(mid,nums);
            if(count>=k){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};