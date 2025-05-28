#include<bits/stdc++.h>
using namespace std;
// aggresive cows;
// User function Template for C++

class Solution {
  public:
    int n;
    bool isPossible(int ele,vector<int>& vec,int k){
        int start=vec[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(vec[i]>=start+ele){
                count++;
                start=vec[i];
            }
        }
        if(count>=k) return true;
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int start=0;
        int end=stalls[n-1]-stalls[0];
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(mid,stalls,k)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};