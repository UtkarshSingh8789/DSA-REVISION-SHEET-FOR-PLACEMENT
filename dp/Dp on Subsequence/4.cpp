#include<bits/stdc++.h>
using namespace std;
// TIME COMPLEXITY-O(N^2);
// There are O(n^2) possible (i, j) pairs (0 ≤ i ≤ j < n).

// Each (i, j) is computed at most once due to memoization.

// Each solve(i, j) call (after memoization) does constant work: check s[i] == s[j], and call at most one more subproblem.

// 🔹 So, total recursive calls = O(n²)
// 🔹 Each call takes O(1) time
// ➡️ Total for solve = O(n²)

class Solution {
public:
    int n;
    int dp[1001][1001];
    bool solve(int i,int j,string& s){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s);
        return dp[i][j]=false;
    }// this bool function is taking constant time because of dp;
    string longestPalindrome(string s) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        int maxi=0;
        int index=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)==true){
                    if((j-i+1)>maxi){
                        maxi=j-i+1;
                        index=i;
                    }
                }
            }
        }
        return s.substr(index,maxi);
    }
};