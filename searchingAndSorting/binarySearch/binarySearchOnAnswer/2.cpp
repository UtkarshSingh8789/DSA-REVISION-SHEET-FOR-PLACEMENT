#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    bool isPossible(int ele,vector<int>& bloomDay,int m,int k){
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(ele>=bloomDay[i]){
                count1++;
                if(count1%k==0){
                    count2++;
                    if(count2>=m) return true;
                }
            }
            else{
                count1=0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        n=bloomDay.size();
        if((long long)m*(long long)k>n) return -1;
        int start=1;
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(mid,bloomDay,m,k)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};