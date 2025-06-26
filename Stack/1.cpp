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
int n;
vector<int> prevelement(vector<int>& heights){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int current=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=current){
            st.pop();
        }
        ans[i]=st.top();
        //cout<<ans[i]<<" ";
        st.push(i);
    }
    //cout<<endl;
    return ans;

}
vector<int> nextelement(vector<int>& heights){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=(n-1);i>=0;i--){
        int current=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=current){
            st.pop();
        }
        ans[i]=st.top();
        //cout<<ans[i]<<" ";
        st.push(i);
    }
    //cout<<endl;
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        n=heights.size();
        vector<int> prev=prevelement(heights);
        vector<int> next=nextelement(heights);
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int length=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int width=(next[i]-prev[i]-1);
            int area=(length*width);
            if(maxArea<area){
                maxArea=area;
            }

        }
        return maxArea;
    }
};