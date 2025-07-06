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
    string removeKdigits(string nums, int k) {
        int n=nums.size();
        // monotonic stack -> if i want to use monotonic dequee the i will use only pop_back() and push_back() that is similar to stack thats why use stack only;
        if(n==k) return "0";
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>nums[i]){
                st.pop();
                k--;
            }
            st.push(nums[i]);
            if(st.size()==1 && st.top()=='0'){
                st.pop();
            }
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.length()==0) return "0";
        return ans;
    }
};