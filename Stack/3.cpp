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
// NGE-2;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 1,2,3,4,3,1,2,3,4,3;
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=0;i<2*n;i++){
            while(!st.empty() && nums[i%n]>nums[st.top()]){
                ans[st.top()]=nums[i%n];
                st.pop();
            }
            if(i<n) st.push(i);
        }
        return ans;
    }
};