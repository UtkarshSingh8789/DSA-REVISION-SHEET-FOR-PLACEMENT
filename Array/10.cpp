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
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        unordered_map<int,int> umpp;
        umpp[0]=-1;
        int count=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) count++;
            else count--;
            if(umpp.find(count)!=umpp.end()){
                maxi=max(maxi,i-umpp[count]);
            }
            else{
                umpp[count]=i;
            }
        }
        return maxi;
    }
};