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
    const int MOD=1e9+7;
    int threeSumMulti(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum>target){
                    end--;
                }
                else if(sum<target){
                    start++;
                }
                else{
                    if(nums[start]==nums[end]){ // YE CASE CHHUT JAATA HAI
                        int freq=end-start;
                        ans=(ans+((freq*(freq+1))/2)%MOD)%MOD;
                        break;
                    }
                    else{
                        int count1=1;
                        start++;
                        while(nums[start]==nums[start-1]){
                            count1++;
                            start++;
                        }
                        int count2=1;
                        end--;
                        while(nums[end]==nums[end+1]){
                            count2++;
                            end--;
                        }
                        ans=(ans+(count1*count2)%MOD)%MOD;
                    }
                }
            }
        }
        return ans%MOD;
    }
};