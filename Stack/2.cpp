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
// maximal rectangle;

// VVI -> EVERY ROW LARGEST RECTANGE IN HISTOGRAM KI TRH VISUALIZE KRO;
class Area {
public:
    int n;
    vector<int> prev_smaller(vector<int>& nums){
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> next_smaller(vector<int>& nums){
        stack<int> st;
        vector<int> ans(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        n=heights.size();
        vector<int> vec1=prev_smaller(heights);
        vector<int> vec2=next_smaller(heights);
        int maxi=0;
        for(int i=0;i<n;i++){
            int ele1=vec1[i];
            int ele2=vec2[i];
            int len=heights[i];
            int breadth=(ele2-ele1-1);
            int area=len*breadth;
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        Area a1;
        vector<vector<int>> preffix(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                if((matrix[i][j]-'0')==0){
                    sum=0;
                }
                else sum=sum+(matrix[i][j]-'0');
                preffix[i][j]=sum;
            }
        }
        int maxi=0;
        for(int i=0;i<m;i++){
            int val=a1.largestRectangleArea(preffix[i]);
            cout<<val<<endl;
            maxi=max(maxi,val);
        }
        return maxi;
    }
};