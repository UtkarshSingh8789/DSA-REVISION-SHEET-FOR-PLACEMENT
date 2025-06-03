#include<bits/stdc++.h>
using namespace std;

// dekho minimumum swaps to make array increasing me array sorted tha isliye humlog prev leke nhi chl
// rhe the kyuki ushka prev humesa index-1 hoga uska follow up me ye puchha jaa skta hai

class Solution {
public:
    int n1;
    int n2;
    map<pair<int,int>,int> dp;
    int solve(int i,int prev,vector<int>& arr1,vector<int>& arr2){
        if(i>=n1) return 0;
        if(dp.find({i,prev})!=dp.end()) return dp[{i,prev}];
        int ans=1e9;
        if(arr1[i]>prev){
            ans=min(ans,solve(i+1,arr1[i],arr1,arr2));
        }
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        if(it<arr2.end()){
            ans=min(ans,1+solve(i+1,*it,arr1,arr2));
        }
        return dp[{i,prev}]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n1=arr1.size();
        n2=arr2.size();
        sort(arr2.begin(),arr2.end());
        int ans=solve(0,-1e9,arr1,arr2);
        if(ans>=1e9) return -1;
        return ans;
    }
};