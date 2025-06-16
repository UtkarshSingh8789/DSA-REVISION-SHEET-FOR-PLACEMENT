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
// airthmetic slices;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int count=0;
        for(int i=0;i<n-2;i++){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                count++;
            }
            else{
                ans=ans+((count)*(count+1))/2;
                count=0;
            }
        }
        if(count) ans=ans+((count)*(count+1))/2;
        return ans;
    }
};