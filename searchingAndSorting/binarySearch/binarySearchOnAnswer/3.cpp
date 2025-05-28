#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int start=1;
        int end=*max_element(piles.begin(),piles.end());
        while(start<end){
            int mid=start+(end-start)/2;
            int newHours=0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid==0){
                    newHours=newHours+piles[i]/mid;
                }
                else{
                    newHours=newHours+((piles[i]/mid)+1);
                }
            }
            if(newHours<=h){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return end;
    }
};