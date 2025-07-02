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
// very inportant 10/3=3 and 3->011 -> (3<<1)+(3<<0) observe l;ike this very inportant concept;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(dividend==divisor) return 1;
        bool flag=false;
        if(dividend>0 && divisor<0) flag=true;
        if(dividend<0 && divisor>0) flag=true;
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);
        long long ans=0;
        while(n>=d){
            int count=0;
            while(n>=d<<(count+1)){
                count++;
            }
            ans=ans+(1<<count);
            n=n-(d<<count);
        }
        if(ans==(1<<31) && flag==false) return INT_MAX;
        if(ans==(1<<31) && flag==true) return INT_MIN;
        return flag? -ans : ans;
    }
};