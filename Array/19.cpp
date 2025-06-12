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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int start=newInterval[0];
        int end=newInterval[1];
        while(i<n && intervals[i][0]<=end){
            start=min(start,intervals[i][0]);
            end=max(end,intervals[i][1]);
            i++;
        }
        ans.push_back({start,end});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};