#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            bool leftSame=(mid>0&&nums[mid]==nums[mid-1]);
            bool rightSame=(mid<n-1&&nums[mid]==nums[mid+1]);
            if(!leftSame && !rightSame) return nums[mid];
            if(((mid)%2==0 && rightSame) || ((mid)%2==1 &&leftSame)){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
};