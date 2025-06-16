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
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        unordered_map<char,int> umpp;
        for(int i=0;i<m;i++){
            umpp[t[i]]++;
        }
        int count=0;
        int i=0;
        int j=0;
        int index=-1;
        int mini=1e9;
        while(j<n){
            char ch=s[j];
            if(umpp[ch]>0) count++;
            umpp[ch]--;
            while(count==m){
                char ch=s[i];
                if((j-i+1)<mini){
                    mini=j-i+1;
                    index=i;
                }
                umpp[ch]++;
                if(umpp[ch]>0) count--;
                i++;
            }
            j++;
        }
        if(index==-1) return "";
        return s.substr(index,mini);
    }
};