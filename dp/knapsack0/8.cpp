#include<bits/stdc++.h>
using namespace std;

// dekho is question ko three variable leke solve kr skte hai ek index ek left heihgt and ek right height
// aur humkoheight equal dikhana hai if(equal return 0) to ek variable me humlog difference store kr rhe

//TLE

class Solution {
public:
    int n;
    int solve(int i,int l1,int l2,vector<int>& rods){
        if(i>=n){
            int maxi=-1e9;
            if(l1==l2){
                maxi=max(maxi,l1);
            }
            return maxi;
        }
        int not_take=solve(i+1,l1,l2,rods);
        int take_1=solve(i+1,l1+rods[i],l2,rods);
        int take_2=solve(i+1,l1,l2+rods[i],rods);
        return max(not_take,max(take_1,take_2));
    }
    int tallestBillboard(vector<int>& rods) {
        n=rods.size();
        int ans=solve(0,0,0,rods);
        return ans;
    }
};

//OPTIMIZE APPROCH

class Solution {
public:
    int n;
    unordered_map<int,unordered_map<int,int>> dp;
    int solve(int i,int j,vector<int>& rods){
        if(i>=n){
            if(j==0){
                return 0;
            }
            return -1e9;
        }
        if(dp.find(dp[i][j])==dp.end()) return dp[i][j];
        int not_take=solve(i+1,j,rods);
        int take_1=rods[i]+solve(i+1,j+rods[i],rods);
        int take_2=rods[i]+solve(i+1,j-rods[i],rods);
        return dp[i][j]=max(not_take,max(take_1,take_2));
    }
    int tallestBillboard(vector<int>& rods) {
        n=rods.size();
        int ans=solve(0,0,rods);
        return ans/2;//INPORTANT
    }
};