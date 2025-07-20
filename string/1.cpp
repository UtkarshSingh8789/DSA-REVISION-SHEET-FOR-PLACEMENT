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
    long long findPallindromicNum(long long ele,bool flag){
        string s=to_string(ele);
        if(flag==true){
            string str=s;
            for(int i=s.length()-1;i>=0;i--){
                str.push_back(s[i]);
            }
            return stoll(str);
        }
        else{
            string str=s;
            for(int i=s.length()-2;i>=0;i--){
                str.push_back(s[i]);
            }
            return stoll(str);
        }
    }
    string nearestPalindromic(string s) {
        int n=s.length();
        int mid=(n/2);
        if(n%2!=0)mid=mid+1;
        long long num=stoll(s);
        long long first_half=stoll(s.substr(0,mid));
        vector<long long> vec;
        vec.push_back(findPallindromicNum(first_half,(n%2==0)));
        vec.push_back(findPallindromicNum(first_half+1,(n%2==0)));
        vec.push_back(findPallindromicNum(first_half-1,(n%2==0)));
        vec.push_back(stoll("1"+string(n,'0'))+1);
        if(n>1){
            vec.push_back(stoll(string(n-1,'9')));
        } else {
            vec.push_back(0);
        }
        long long mini=LLONG_MAX;
        long long result=LLONG_MAX;
        for(int i=0;i<vec.size();i++){
            long long new_num=vec[i];
            if(new_num==num)continue;
            if(abs(new_num-num)<mini){
                mini=abs(new_num-num);
                result=new_num;
            }
            else if(abs(new_num-num)==mini){
                if(new_num<result){
                    result=new_num;
                }
            }
        }
        return to_string(result);
    }
};