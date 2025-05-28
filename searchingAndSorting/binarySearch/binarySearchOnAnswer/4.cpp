#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool helper(int ele,vector<int>& weights, int days){
        int ans=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>ele) return false;
            sum=sum+weights[i];
            if(sum>ele){
                sum=weights[i];
                ans++;
            }
        }
        if(ans<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int start=0;
        int end=1e9;
        int ans=1e9;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(helper(mid,weights,days)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};