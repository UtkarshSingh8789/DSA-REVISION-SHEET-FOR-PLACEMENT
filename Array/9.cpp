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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLength = 0;
        for (int num : nums) {
            if (st.find(num - 1) == st.end()) {
                int current = num;
                int count = 0;
                while (st.find(current) != st.end()) {
                    st.erase(current);
                    current++;
                    count++;
                }
                maxLength = max(maxLength, count);
            }
        }

        return maxLength;
    }
};