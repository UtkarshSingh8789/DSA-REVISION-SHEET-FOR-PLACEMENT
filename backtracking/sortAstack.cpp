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
    void sortedOrder(int ele,stack<int>& st){
        if(st.empty() || st.top()<=ele){
            st.push(ele);
            return;
        }
        auto it=st.top();
        st.pop();
        sortedOrder(ele,st);
        st.push(it);
    }
    void sortTheStack(stack<int>& st){
        if(st.empty()) return;
        auto it=st.top();
        st.pop();
        sortTheStack(st);
        sortedOrder(it,st);
    }
};