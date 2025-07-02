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
  private:
    int findtill(int n){
        // this function will give the xor from 1 to n;
        if(n%4==1) return 1;
        if(n%4==0) return n;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
    }
  public:
    int findXOR(int l, int r) {
        //l=4,3=7;
        // (1^2^3) ^ (1^2^3^4^5^6^7) -> same number xor willl xero hence -> (4^5^6^7);
        int ele1=findtill(r);
        int ele2=findtill(l-1);
        return ele1^ele2;
    }
};