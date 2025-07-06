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
    int n;
    int findCount(int ele,vector<int>& nums){
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            while(i<j && (nums[j]-nums[i])>ele){
                i++;
            }
            count=count+(j-i);
            j++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums[n-1]-nums[0];
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            int count=findCount(mid,nums);
            if(count>=k){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};