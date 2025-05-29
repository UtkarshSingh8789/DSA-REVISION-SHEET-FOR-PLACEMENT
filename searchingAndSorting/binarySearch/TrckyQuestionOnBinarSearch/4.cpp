#include<bits/stdc++.h>
using namespace std;
// find peak element 2
class Solution {
public:
    int m;
    int find_max(int col,vector<vector<int>>& mat){
        int row=0;
        int maxi=0;
        for(int i=0;i<m;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                row=i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        m=mat.size();
        int n=mat[0].size();
        int start=0;
        int end=n-1;
        vector<int> ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            int row=find_max(mid,mat);
            int left=(mid-1)>=0 ? mat[row][mid-1] : -1;
            int right=(mid+1)<n ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                ans={row,mid};
                break;
            }
            else if(mat[row][mid]<left){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};