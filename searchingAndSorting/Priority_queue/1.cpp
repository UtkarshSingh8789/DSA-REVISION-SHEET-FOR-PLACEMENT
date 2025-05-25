#include<bits/stdc++.h>
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
            int x=it.second.first;
            int y=it.second.second;
            ans.push_back({nums1[x],nums2[y]});
            k--;
            if(y+1<n2){
                int sum=nums2[y+1]+nums1[x];
                pq.push({sum,{x,y+1}});
            }
        }
        return ans;
    }
};