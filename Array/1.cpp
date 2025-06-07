// minimu swaps to sort an array;
// using cycle detection technique;
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
class Solution{
    public:
    int minSwapsToSortAnArray(vector<int>& arr){
        int n=arr.size();
        unordered_map<int,bool> visited;
        unordered_map<int,int> umpp;
        for(int i=0;i<n;i++){
            umpp[arr[i]]=i;
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==umpp[arr[i]] || visited[i]) continue;
            int j=i;
            int count=0;
            while(!visited[j]){
                visited[j]=true;
                j=umpp[arr[j]];
                count++;
            }
            if(count>0) ans=ans+(count-1);
        }
        return ans;
    }
};
int main(){

}