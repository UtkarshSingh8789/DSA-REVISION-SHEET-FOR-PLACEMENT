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

//VERY INPORTANT ALGORITHM DUTCH NATIONAL FLAG ALGORITHM;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int mid=0;
        while(mid<=j){
            if(nums[mid]==0){
                swap(nums[mid],nums[i]);
                i++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[j]);
                j--;
            }
        }
    }
};