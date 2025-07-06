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
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        map<vector<int>,bool> mpp;
        vector<int> vec(m,0);
        int sum=0;
        for(int i=0;i<m;i++){
            sum=sum+mat[i][0];
        }
        pq.push({sum,vec});
        mpp[vec]=true;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int sum=it.first;
            vector<int> temp=it.second;
            k--;
            if(k==0) return sum;
            for(int i=0;i<temp.size();i++){
                int sum1=it.first;
                vector<int> temp=it.second;
                int j=temp[i];
                sum1=sum1-mat[i][j];
                if(j+1<n){
                    sum1=sum1+mat[i][j+1];
                    temp[i]=j+1;
                }
                if(!mpp[temp]){
                    mpp[temp]=true;
                    pq.push({sum1,temp});
                }
            }
        }
        return -1;
    }
};