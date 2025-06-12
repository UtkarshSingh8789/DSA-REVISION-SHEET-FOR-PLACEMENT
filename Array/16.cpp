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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(target-sum);
                if(diff<mini){
                    mini=diff;
                    ans=sum;
                }
                if(sum>target){
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    return sum;//YE  CASE MT BHULNA TLE HOJAYEGA
                }
            }
        }
        return ans;
    }
};