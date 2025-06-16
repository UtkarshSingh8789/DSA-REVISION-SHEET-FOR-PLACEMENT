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
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0, j = 0, count = 0;
        int minLen = INT_MAX;
        string ans = "";

        while (j < n) {
            if (s[j] == '1') count++;

            // Shrink the window as long as count >= k
            while (count >= k) {
                if (count == k) {
                    int len = j - i + 1;
                    string temp = s.substr(i, len);
                    if (len < minLen) {
                        minLen = len;
                        ans = temp;
                    } else if (len == minLen && temp < ans) {
                        ans = temp;
                    }
                }
                if (s[i] == '1') count--;
                i++;
            }

            j++;
        }

        return ans;
    }
};