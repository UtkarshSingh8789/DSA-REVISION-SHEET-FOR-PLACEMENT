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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> umpp;
        umpp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(umpp.find(sum-goal)!=umpp.end()){
                ans=ans+umpp[sum-goal];
            }
            umpp[sum]++;
        }
        return ans;
    }
};