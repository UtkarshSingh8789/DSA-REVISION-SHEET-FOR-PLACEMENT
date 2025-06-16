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
// very inportant pattern if we are talking about exact then this can help;
class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int i = 0, j = 0, ans = 0;
        unordered_map<int, int> umpp;
        while (j < nums.size()) {
            umpp[nums[j]]++;
            while (umpp.size() > k) {
                umpp[nums[i]]--;
                if (umpp[nums[i]] == 0) {
                    umpp.erase(nums[i]);
                }
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};