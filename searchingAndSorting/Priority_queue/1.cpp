// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
// Define a pair (u, v) which consists of one element from the first array and one element from the second array.
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

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