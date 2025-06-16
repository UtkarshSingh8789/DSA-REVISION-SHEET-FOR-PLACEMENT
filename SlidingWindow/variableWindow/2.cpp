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
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        unordered_map<int,int> umpp;
        int maxi=0;
        int ans=0;
        while(j<n){
            int ele=nums[j];
            umpp[ele]++;
            maxi=max(maxi,umpp[ele]);
            while(((j-i+1)-maxi)>k){
                umpp[nums[i]]--;
                i++;
            }
            ans=max(ans,maxi);
            j++;
        }
        return ans;
    }
};