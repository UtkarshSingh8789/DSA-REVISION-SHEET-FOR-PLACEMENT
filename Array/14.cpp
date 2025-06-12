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
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            int ele=nums[i];
            if(maxi>ele){
                index=i;
                break;
            }
            maxi=max(maxi,ele);
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int ind2=-1;
        for(int i=index+1;i<n;i++){
            if(nums[i]>nums[index]){
                ind2=i;
            }
        }
        swap(nums[ind2],nums[index]);
        reverse(nums.begin()+index+1,nums.end());
    }
};