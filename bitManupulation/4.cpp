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
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<32;i++){
            int mask=1<<i;
            int a1=a&mask;
            int b1=b&mask;
            int c1=c&mask;
            if(c1==0){
                if(a1>0 && b1>0) ans=ans+2;
                else if(a1==0 && b1==0) ans=ans+0;
                else ans=ans+1;
            }
            else{
                if(a1==0 && b1==0) ans=ans+1;
            }
        }
        return ans;
    }
};