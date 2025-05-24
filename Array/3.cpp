#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> suff(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i];
        }
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]*nums[i];
        }
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            if((i-1)>=0){
                ans[i]=ans[i]*pre[i-1];
            }
            if((i+1)<n){
                ans[i]=ans[i]*suff[i+1];
            }
        }
        return ans;
    }
};