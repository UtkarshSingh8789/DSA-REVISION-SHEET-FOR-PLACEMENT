#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     #define ll long long
//     long long minNumberOfSeconds(int h, vector<int>& nums) {
//         int n=nums.size();
//         priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
//         for(int i=0;i<n;i++){
//             pq.push({nums[i],{nums[i],2}});
//         }
//         ll maxi=0;
//         while(h>0){
//             auto it=pq.top();
//             pq.pop();
//             ll val=it.first;
//             ll base=it.second.first;
//             ll count=it.second.second;
//             maxi=max(maxi,val);
//             h--;
//             pq.push({base*count+val,{base,count+1}});
//         }
//         return maxi;
//     }
// };// follow up can we reomve space of priority queue;
class Solution {
public:
    long long f(vector<int>& v, long long mountainHeight, long long target) {
        long long sum = 0;
        for(auto w: v) {
            long long lo = 1, hi = mountainHeight, ans = 0;
            while(lo <= hi) {
                long long mi = (lo + hi)/2;
                if(w * ((mi * (mi + 1))/2) <= target) ans = mi, lo = mi+1;
                else hi = mi-1;
            }
            sum += ans;
        }
        return sum >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& w) {
        int n = w.size();
        sort(w.begin(), w.end());
        long long lo = 1, hi = 1e18, ans = hi;
        while(lo <= hi) {
            long long mi = lo + (hi - lo)/2;
            if(f(w, mountainHeight, mi)) ans = mi, hi = mi-1;
            else lo = mi + 1;
        }
        return ans;
    }
};