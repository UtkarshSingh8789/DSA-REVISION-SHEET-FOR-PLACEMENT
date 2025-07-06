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

// VVI WHENEVER WE HAVE TO FIND MIN AND MAX FROM EVERY SUBARRAY WE USE STACK AND USE THE CONCEPT OF
// NGE,PGE,NSE,PSE;
class Solution {
public:
    int n;
    vector<int> prev_smaller(vector<int>& nums){
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> next_smaller(vector<int>& nums){
        stack<int> st;
        vector<int> ans(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> prev_greater(vector<int>& nums){
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> next_greater(vector<int>& nums){
        stack<int> st;
        vector<int> ans(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        n=nums.size();
        long long ans=0;
        vector<int> nextmax=next_greater(nums);
        vector<int> prevmax=prev_greater(nums);
        vector<int> nextmin=next_smaller(nums);
        vector<int> prevmin=prev_smaller(nums);
        for(int i=0;i<n;i++){
            long long max_contrib=(long long)nums[i]*(nextmax[i]-i)*(i-prevmax[i]);
            long long min_contrib=(long long)nums[i]*(nextmin[i]-i)*(i-prevmin[i]);
            ans+=max_contrib-min_contrib;
        }
        return ans;
    }
};