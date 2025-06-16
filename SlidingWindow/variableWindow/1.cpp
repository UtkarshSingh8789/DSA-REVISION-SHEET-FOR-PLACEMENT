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
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int i=0;
        int j=0;
        unordered_map<int,int> umpp;
        int mini=1e9;
        while(j<n){
            int ele=cards[j];
            umpp[ele]++;
            while(((j-i+1)-umpp.size())==1){
                mini=min(mini,j-i+1);
                int ele=cards[i];
                umpp[ele]--;
                if(umpp[ele]==0) umpp.erase(ele);
                i++;
            }
            j++;
        }
        if(mini==1e9) return -1;
        return mini;
    }
};