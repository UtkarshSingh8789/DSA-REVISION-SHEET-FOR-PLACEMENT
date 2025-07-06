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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n1;i++){
            int sum=nums1[i]+nums2[0];
            pq.push({sum,{i,0}});
        }
        vector<vector<int>> ans;
        while(!pq.empty() && k>0){
            auto it=pq.top();
            pq.pop();
            int sum=it.first;
            int i=it.second.first;
            int j=it.second.second;
            ans.push_back({nums1[i],nums2[j]});
            k--;
            if(j+1<n2){
                int sum=nums1[i]+nums2[j+1];
                pq.push({sum,{i,j+1}});
            }
        }
        return ans;
    }
};