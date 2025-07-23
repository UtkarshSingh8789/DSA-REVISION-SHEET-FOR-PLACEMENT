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
class Solution{
public:
    vector<int> countingSort(vector<int>& nums){
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        vector<int> count(maxi-mini+1,0);
        for(int i=0;i<n;i++){
            int ele=nums[i]-mini;
            count[ele]++;
        }
        for(int i=1;i<(maxi-mini+1);i++){
            count[i]=count[i-1]+count[i];
        }
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int ele=nums[i]-mini;
            count[ele]=count[ele]-1;
            ans[count[ele]]=ele+mini;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={4,-2,-2,8,3,-3,1};
    vector<int> SortedArray=s.countingSort(nums);
    for(auto it:SortedArray){
        cout<<it<<" ";
    }
}