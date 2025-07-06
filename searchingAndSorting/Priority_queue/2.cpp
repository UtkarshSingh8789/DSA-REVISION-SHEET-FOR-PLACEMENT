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
    const int MOD=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        int count1=left;
        int count2=right-left+1;
        int sum=0;
        while(!pq.empty() && count2>0){
            auto it=pq.top();
            pq.pop();
            count1--;
            if(count1<=0){
                cout<<it.first<<endl;
                sum=(sum+it.first%MOD)%MOD;
                count2--;
                if(count2==0) break;
            }
            int index=it.second;
            if((index+1)<n){
                int ele=(it.first+nums[index+1]%MOD)%MOD;
                pq.push({ele,index+1});
            }
        }
        return sum;
    }
}; 