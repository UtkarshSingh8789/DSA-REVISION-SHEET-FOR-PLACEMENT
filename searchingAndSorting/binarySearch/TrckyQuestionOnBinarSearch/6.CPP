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
    int n1;
    int n2;
    int solve(vector<int>& nums1,vector<int>& nums2,int ele){
        int ans=INT_MAX;
        int start=0;
        int end=n2-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int val=nums2[mid];
            int count1=mid+1;
            int count2=upper_bound(nums1.begin(),nums1.end(),val)-nums1.begin();
            int totalCount=count1+count2;
            if(totalCount>=ele+1){
                ans=min(ans,val);
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        start=0;
        end=n1-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int val=nums1[mid];
            int count1=mid+1;
            int count2=upper_bound(nums2.begin(),nums2.end(),val)-nums2.begin();
            int totalCount=count1+count2;
            if(totalCount>=ele+1){
                ans=min(ans,val);
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
        n1=nums1.size();
        n2=nums2.size();
        int ele=(n1+n2)/2;
        if((n1+n2)%2==0){
            int ans1=solve(nums1,nums2,ele);
            int ans2=solve(nums1,nums2,ele-1);
            return (ans1+ans2)/2.0;
        }
        else{
            int ans1=solve(nums1,nums2,ele);
            return ans1*1.0;
        }
    }
};