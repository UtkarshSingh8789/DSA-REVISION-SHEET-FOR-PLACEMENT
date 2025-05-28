#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int count_val(int mid,vector<vector<int>>& matrix){
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<n && j>=0){
            int ele=matrix[i][j];
            if(ele<=mid){
                ans=ans+j+1;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n=matrix.size();
        int start=matrix[0][0];
        int end=matrix[n-1][n-1];
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(count_val(mid,matrix)>=k){
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