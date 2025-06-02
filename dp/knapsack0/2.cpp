#include<bits/stdc++.h>
using namespace std;

//RECURSIVE
class Solution {
public:
    int n;
    int m;
    int solve(int i,vector<int>& price,vector<vector<int>>& special,vector<int>& needs){
        if(i>=n){
            int ans=0;
            for(int j=0;j<m;j++){
                ans=ans+price[j]*needs[j];
            }
            return ans;
        }
        int not_take=solve(i+1,price,special,needs);
        int take=1e9;
        bool flag=true;
        for(int j=0;j<m;j++){
            needs[j]=needs[j]-special[i][j];
            if(needs[j]<0){
                flag=false;
            }
        }
        if(flag){
            take=special[i][m]+solve(i,price,special,needs);
        }
        for(int j=0;j<m;j++){
            needs[j]=needs[j]+special[i][j];
        }//BACKTRACKING***
        return min(take,not_take);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n=special.size();
        m=price.size();
        int ans=solve(0,price,special,needs);
        return ans;
    }
};

// MEMOIZATON
class Solution {
public:
    int n;
    int m;
    unordered_map<string,int> memo;
    string serialize(int i, vector<int>& needs) {
        string key=to_string(i)+"|";
        for(int x : needs) key+=to_string(x)+"#";
        return key;
    }
    int solve(int i,vector<int>& price,vector<vector<int>>& special,vector<int>& needs){
        if(i>=n){
            int ans=0;
            for(int j=0;j<m;j++){
                ans=ans+price[j]*needs[j];
            }
            return ans;
        }
        string key=serialize(i,needs);
        if(memo.count(key)) return memo[key];

        int not_take=solve(i+1,price,special,needs);
        int take=1e9;
        bool flag=true;
        for(int j=0;j<m;j++){
            needs[j]=needs[j]-special[i][j];
            if(needs[j]<0){
                flag=false;
            }
        }
        if(flag){
            take=special[i][m]+solve(i,price,special,needs);
        }
        for(int j=0;j<m;j++){
            needs[j]=needs[j]+special[i][j];
        }
        return memo[key]=min(take,not_take);
    }
    int shoppingOffers(vector<int>& price,vector<vector<int>>& special,vector<int>& needs){
        n=special.size();
        m=price.size();
        int ans=solve(0,price,special,needs);
        return ans;
    }
};