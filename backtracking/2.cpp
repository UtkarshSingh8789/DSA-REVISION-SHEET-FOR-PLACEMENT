#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isSafe(int i,int j,int n,vector<string>& vec){
            // upper diagonal,lower diagonal,back horizontal;
            int row=i;
            int col=j;
            while(col>=0){
                if(vec[row][col]=='Q') return false;
                col--;
            }
            row=i;
            col=j;
            while(row<n && col>=0){
                if(vec[row][col]=='Q') return false;
                row++;
                col--;
            }
            row=i;
            col=j;
            while(row>=0 && col>=0){
                if(vec[row][col]=='Q') return false;
                row--;
                col--;
            }
            return true;
        }
        int solve(int n,int i,vector<string>& vec){
            if(i>=n) return 1;
            int ans=0;
            for(int row=0;row<n;row++){
                if(isSafe(row,i,n,vec)){
                    vec[row][i]='Q';
                    ans=ans+solve(n,i+1,vec);
                    vec[row][i]='.';
                }
            }
            return ans;
        }
        int totalNQueens(int n) {
            vector<string> vec(n,string(n,'.'));
            int count=solve(n,0,vec);
            return count;
        }
    };