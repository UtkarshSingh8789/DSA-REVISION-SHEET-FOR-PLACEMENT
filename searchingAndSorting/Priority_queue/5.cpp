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
// VVI;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;//min heap;
        vector<int> temp(n,0);
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],i,0});
            maxi=max(maxi,nums[i][0]);
        }
        vector<int> ans(2);
        int mini=1e9;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int curr_ele=it[0];
            int row=it[1];
            int col=it[2];
            if(mini>(maxi-curr_ele)){
                mini=(maxi-curr_ele);
                ans[0]=curr_ele;
                ans[1]=maxi;
            }
            if(col+1<nums[row].size()){
                int next_element=nums[row][col+1];
                pq.push({next_element,row,col+1});
                maxi=max(maxi,nums[row][col+1]);
            }
            else break;
        }
        return ans;
    }
};