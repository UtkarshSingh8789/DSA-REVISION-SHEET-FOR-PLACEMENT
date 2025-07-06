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
// asteroid colllision;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            bool flag=false;
            while(!st.empty() && nums[i]<0 && st.top()>0){
                int sum=st.top()+nums[i];
                if(sum<0){
                    st.pop();
                }
                else if(sum>0){
                    flag=true;
                    break;
                }
                else{
                    st.pop();
                    flag=true;
                    break;
                }
            }
            if(!flag){
                st.push(nums[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};