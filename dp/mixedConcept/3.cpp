#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
class Solution {
public:
    int n;
    int find(int i,vector<vector<int>>& events){
        int start=i+1;
        int end=n-1;
        int ans=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(events[mid][0]>events[i][1]){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
    int solve(int i,int j,vector<vector<int>>& events,vector<vector<int>>& dp){
        if(j<=0) return 0;
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int not_take=solve(i+1,j,events,dp);
        int take=events[i][2]+solve(find(i,events),j-1,events,dp);
        return dp[i][j]=max(take,not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int ans=solve(0,k,events,dp);
        return ans;
    }
};