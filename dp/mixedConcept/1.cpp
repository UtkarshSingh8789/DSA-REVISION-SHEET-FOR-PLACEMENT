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


// IMP-CONCEPT -> WE WILL LEARN ABOUT PRINITING THE VECTOR AND USING PREFIX AND DYNAMIC PROGRAMING TOGETHER;
// THAUGHT PROCESS -> WHY DP?
// because we can start from any point in array and we rto take exact 3 subbaray;
// if e take 0 start for first subaary then 3,4,5 any can be start for second and so on for third;
// means so many possiblity -> recursion -> memoization because of overlaaping sub interval;
// prefix sum-> because we have to find sum of subarray in  constant time;
class Solution {
public:
    vector<int> pre;
    int dp[20002][4];
    int n;
    int solve1(int i,int j,int k,vector<int>& nums){
        if(j==0) return 0;
        if(i>=n){
            return -1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int not_take=solve1(i+1,j,k,nums);
        int take=-1e9;
        if((i+k)<=n){
            take=pre[i+k]-pre[i]+solve1(i+k,j-1,k,nums);
        }
        return dp[i][j]=max(take,not_take);
    }
    void solve2(int i,int j,int k,vector<int>& nums,vector<int>& ans){
        if(i>=n) return;
        if(j==0) return;
        int startHere=pre[i+k]-pre[i]+solve1(i+k,j-1,k,nums);
        int notStartHere=solve1(i+1,j,k,nums);
        if(startHere>=notStartHere){
            ans.push_back(i);
            solve2(i+k,j-1,k,nums,ans);
        }
        else{
            solve2(i+1,j,k,nums,ans);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k){
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        pre.resize(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        solve1(0,3,k,nums);
        vector<int> ans;
        solve2(0,3,k,nums,ans);
        return ans;
    }
};