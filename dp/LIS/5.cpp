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

// VVI

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }
        vector<int> dp2(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    dp2[i]=max(dp2[i],dp2[j]+1);
                }
            }
        }
        int mini=n;
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1){
                mini=min(mini,(n-(dp1[i]+dp2[i]-1)));
            }
        }
        return mini;
    }
};

// VVI -> APPROCH 2 USING BINARY SEARCH;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,1);
        vector<int> LIS;
        LIS.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>LIS.back()){
                dp1[i]=LIS.size()+1;
                LIS.push_back(nums[i]);
            }
            else{
                int index=lower_bound(LIS.begin(),LIS.end(),nums[i])-LIS.begin();
                LIS[index]=nums[i];
                dp1[i]=index+1;
            }
        }
        vector<int> dp2(n,1);
        vector<int> LDS;
        LDS.push_back(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            if(nums[i]>LDS.back()){
                dp2[i]=LDS.size()+1;
                LDS.push_back(nums[i]);
            }
            else{
                int index=lower_bound(LDS.begin(),LDS.end(),nums[i])-LDS.begin();
                LDS[index]=nums[i];
                dp2[i]=index+1;
            }
        }
        int minimumOperation=n;
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1){
                int numOperations=n-(dp1[i]+dp2[i]-1);
                minimumOperation=min(minimumOperation,numOperations);
            }
        }
        return minimumOperation;
    }
};