#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void merge(int start,int mid,int end,vector<int>& nums){
        int n1=mid-start+1;
        int n2=end-mid;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i=start;i<=mid;i++){
            left[i-start]=nums[i];
        }
        for(int i=mid+1;i<=end;i++){
            right[i-(mid+1)]=nums[i];
        }
        int i=0;
        int j=0;
        int k=start;
        while(i<n1 && j<n2){
            if(left[i]>=right[j]){
                nums[k]=right[j];
                k++;
                j++;
            }
            else{
                nums[k]=left[i];
                k++;
                i++;
            }
        }
        while(i<n1){
            nums[k]=left[i];
            k++;
            i++;
        }
        while(j<n2){
            nums[k]=right[j];
            k++;
            j++;
        }
    }
    void mergeSort(int start,int end,vector<int>& nums){
        if(start>=end) return;
        int mid=start+(end-start)/2;
        mergeSort(start,mid,nums);
        mergeSort(mid+1,end,nums);
        merge(start,mid,end,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(0,n-1,nums);
        return nums;
    }
};