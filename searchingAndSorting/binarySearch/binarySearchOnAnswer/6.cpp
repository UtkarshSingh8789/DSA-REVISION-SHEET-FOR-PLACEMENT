#include<bits/stdc++.h>
using namespace std;
// book allocation
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[],int n,int m,int sol){
    int sum=0;
    int count=1;
    for(int i=0;i<n;i++){
        if(A[i]>sol){
            return false;
        }
        if(sum+A[i]>sol){
            count++;
            sum=A[i];
            if(count>m){
                return false;
            }
        }
        else{
            sum=sum+A[i];
        }
    }
    return true;
}
    int findPages(int A[], int N, int M){
        
        if(M>N){
            return -1;
        }
        int start=0;
        int end=accumulate(A,A+N,0);
        while(start<end){
            int mid=start+(end-start)/2;
            if(isPossible(A,N,M,mid)){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return end;
    }
};