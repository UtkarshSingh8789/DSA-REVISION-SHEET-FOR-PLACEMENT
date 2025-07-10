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
    vector<string> ans;
    void dfs(int count_open,int count_close,string& s){
        if(count_open==0 && count_close==0){
            ans.push_back(s);
            return;
        }
        if(count_open>0){
            s.push_back('(');
            dfs(count_open-1,count_close,s);
            s.pop_back();
        }
        if(count_close>0 && count_open<count_close){
            s.push_back(')');
            dfs(count_open,count_close-1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        int count_open=n;
        int count_close=n;
        dfs(count_open,count_close,s);
        return ans;
    }
};