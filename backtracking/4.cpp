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
    int n;
    void dfs(int i,string& str,string& num,long long cnt,long long prev,int target){
        if(i>=n){
            if(cnt==target){
                ans.push_back(str);
            }
            return;
        }
        long long val=0;
        for(int j=i;j<n;j++){
            val=val*10+(num[j]-'0');
            string s1=num.substr(i,j-i+1);
            if(s1.size()>1&&s1[0]=='0')break;
            int prev_len=str.size();
            str=str+"+"+s1;
            dfs(j+1,str,num,cnt+val,val,target);
            str.resize(prev_len);
            str=str+"-"+s1;
            dfs(j+1,str,num,cnt-val,-val,target);
            str.resize(prev_len);
            str=str+"*"+s1;
            dfs(j+1,str,num,cnt-prev+prev*val,prev*val,target);
            str.resize(prev_len);
        }
    }
    vector<string> addOperators(string num,int target){
        n=num.length();
        long long val=0;
        for(int j=0;j<n;j++){
            val=val*10+(num[j]-'0');
            string s1=num.substr(0,j+1);
            if(s1.size()>1&&s1[0]=='0')break;
            string str=s1;
            dfs(j+1,str,num,val,val,target);
        }
        return ans;
    }
};