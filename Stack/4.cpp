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
// min stack
class MinStack {
public:
    stack <pair <int,int>> st;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else{
            pair <int,int> p = st.top();
            if(p.second>val) st.push({val,val});
            else st.push({val,p.second});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        pair <int,int> p = st.top();
        return p.first;
    }
    
    int getMin() {
        pair <int,int> p = st.top();
        return p.second;
    }
};