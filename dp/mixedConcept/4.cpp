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
using namespace std;
class Solution {
public:
    int dp[50001];
    int n;
    int findIndex(int val,vector<vector<int>>& vec){
        int start=0;
        int end=n-1;
        int ans=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(vec[mid][0]>=val){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
    int solve(int i,vector<vector<int>>& vec){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int not_take=solve(i+1,vec);
        int take=vec[i][2]+solve(findIndex(vec[i][1],vec),vec);
        return dp[i]=max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=profit.size();
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            int u=startTime[i];
            int v=endTime[i];
            int w=profit[i];
            vec.push_back({u,v,w});
        }
        sort(vec.begin(),vec.end());
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,vec);
        return ans;
    }
};