#include<bits/stdc++.h>
using namespace std;
// search in rotated sorted array 2
// in this question the nums can contain duplicates. if it contains duplicates we have to take care of one extra edge case
// that is when mid and start and end equal;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[start] && nums[mid]==nums[end]){
                start++;
                end--;
            }// this case is only when the nums contain duplicates;
            else if(nums[start]<=nums[mid]){
                if(nums[start]<=target && nums[mid]>=target){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[end]>=target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};