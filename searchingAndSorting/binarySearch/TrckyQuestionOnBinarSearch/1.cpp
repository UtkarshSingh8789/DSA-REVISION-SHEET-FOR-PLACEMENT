#include<bits/stdc++.h>
using namespace std;
// seacrh in a 2d matrix;
class Solution {
public:
    int n;
    bool isThere(int ele,vector<vector<int>>& matrix,int target){
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[ele][mid]==target) return true;
            else if(matrix[ele][mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int m=matrix.size();
        n=matrix[0].size();
        int row_start=0;
        int row_end=m-1;
        int ans=0;
        while(row_start<=row_end){
            int mid=row_start+(row_end-row_start)/2;
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                if(isThere(mid,matrix,target)) return true;
                else{
                    return false;
                }
            }
            else if(matrix[mid][0]>target){
                row_end=mid-1;
            }
            else{
                row_start=mid+1;
            }
        }
        return false;
    }
};

// follow upp can we do with using single binary search;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int start=0;
        int end=((m*n)-1);
        while(start<=end){
            int mid=(start+((end-start)/2));
            int row=mid/n;
            int column=mid%n;
            if(matrix[row][column]==target){
               return true;

            }
            else if(matrix[row][column]<target){
                start=mid+1;

            }
            else{
                end=mid-1;

            }
        }
        return false;
    }
};
