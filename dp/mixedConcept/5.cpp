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
    int LIS(vector<int>& vec){
        if(vec.size()==0) return 0;
        vector<int> temp;
        temp.push_back(vec[0]);
        for(int i=1;i<vec.size();i++){
            int ele=vec[i];
            if(ele>temp.back()) temp.push_back(ele);
            else{
                int index=lower_bound(temp.begin(),temp.end(),ele)-temp.begin();
                temp[index]=ele;
            }
        }
        cout<<temp.size()<<endl;
        return temp.size();
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        int m=arr.size();
        unordered_map<int,int> umpp;
        for(int i=0;i<n;i++){
            umpp[target[i]]=i;
        }
        vector<int> vec;
        for(int i=0;i<m;i++){
            if(umpp.find(arr[i])!=umpp.end()){
                vec.push_back(umpp[arr[i]]);
            }
        }
        int findLongestIncreasingSub=LIS(vec);
        return n-findLongestIncreasingSub;
    }
};