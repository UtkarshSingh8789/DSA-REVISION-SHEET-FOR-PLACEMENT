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
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int> ans(n);
        // pref[1]=pref[0]^ans[1];
        // 2=5^x
        // a^a=0;
        // a^0=a means if a^x=0 then x=a^0
        ans[0]=pref[0];
        for(int i=1;i<n;i++){
            ans[i]=pref[i]^pref[i-1];
        }
        return ans;
    }
};