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
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int prev=INT_MIN;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(prev>nums[i]){
                cout<<prev<<endl;
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                prev=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};