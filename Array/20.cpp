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
// if all the number is negative or positive or even number of negatives then product of all;
// if there is odd number of negatives like ={2,4,-3,5,7,-8,3,-9,6,5};
// then for -3-> max(product before -3 and product after -3) // because we have to remove one for even number of negatives so we will check for all negatives;
// hence we have to find suffix and prefix;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double prefixProduct = 1;
        double suffixProduct = 1;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefixProduct==0) prefixProduct = 1;
            if(suffixProduct==0) suffixProduct = 1;
            prefixProduct *= (nums[i]);
            suffixProduct *= (nums[nums.size()-i-1]);
            double temp = prefixProduct;
            if(prefixProduct < suffixProduct) temp = suffixProduct;
            if(ans < temp) ans = temp;
        }

        return ans;
    }
};