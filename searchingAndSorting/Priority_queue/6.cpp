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
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n,-1);
        vector<long long> suff(n,-1);
        priority_queue<long long> pq;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            pq.push(nums[i]);
            if(pq.size()>(n/3)){
                auto it=pq.top();
                pq.pop();
                sum=sum-it;
            }
            if(pq.size()==n/3){
                pre[i]=sum;
            }
        }
        sum=0;
        priority_queue<long long,vector<long long>,greater<long long>> pq1;
        for(int i=n-1;i>=0;i--){
            sum=sum+nums[i];
            pq1.push(nums[i]);
            if(pq1.size()>(n/3)){
                auto it=pq1.top();
                pq1.pop();
                sum=sum-it;
            }
            if(pq1.size()==n/3){
                suff[i]=sum;
            }
        }
        long long ans=LONG_MAX;
        for(int i=n/3-1;i<2*n/3;i++){
            if(pre[i]!=-1 && suff[i+1]!=-1){
                ans=min(ans,pre[i]-suff[i+1]);
            }
        }
        return ans;
    }
};