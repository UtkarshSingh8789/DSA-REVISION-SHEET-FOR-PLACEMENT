#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<long long> pre;
    bool isPossible(int ele,vector<int>& nums,long long k){
        int i=0;
        int j=ele-1;
        while(j<n){
            int midind=(i+j)/2;
            int midvalue=nums[midind];
            long long leftSum=pre[midind+1]-pre[i];
            long long leftActual=(midind-i+1)*(long long)midvalue;
            long long leftopp=leftActual-leftSum;
            long long rightSum=pre[j+1]-pre[midind];
            long long rightActual=(j-midind+1)*(long long)midvalue;
            long long rightopp=rightSum-rightActual;
            if(leftopp+rightopp<=k) return true;
            j++;
            i++;
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        pre.assign(n+1,0ll);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+(long long)nums[i];
        }
        int start=1;
        int end=n;
        int ans=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(mid,nums,k)){
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
};