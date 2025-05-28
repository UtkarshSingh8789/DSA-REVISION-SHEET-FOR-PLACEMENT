#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pre;
    int n;
    int solve(int ele,vector<int>& arr){
        auto it=lower_bound(arr.begin(),arr.end(),ele);
        int index=it-arr.begin();
        int left_sum=pre[index];
        int right_sum=(n-index)*ele;
        return left_sum+right_sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        n=arr.size();
        pre.resize(n+1,0);
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+arr[i];
        }
        if(pre[n]<=target) return arr[n-1];
        int start=0;
        int end=*max_element(arr.begin(),arr.end());
        int min_diff=INT_MAX;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            int find_ans=solve(mid,arr);
            int diff=abs(find_ans-target);
            if(diff<min_diff || (diff==min_diff && mid<ans)){
                min_diff=diff;
                ans=mid;
            }
            if(find_ans>=target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
