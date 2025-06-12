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
//BOYER MORE MAJORITY VOTE ALGORITHM;
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele=nums[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                ele=nums[i];
            }
            if(nums[i]==ele) count++;
            else count--;
        }
        return ele;
    }
}; // agr n/2 se jada koi element hoga toh yhi hoga nhi dusra koi nhi to ek baar check krlenge ishka count agr n/2 se jada to return krdenge wana -1