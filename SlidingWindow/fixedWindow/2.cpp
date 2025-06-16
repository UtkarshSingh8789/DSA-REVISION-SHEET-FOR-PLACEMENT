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
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if (m > n) return {};
        vector<int> freqs(26, 0);
        vector<int> freqp(26, 0);
        for (int i = 0; i < m; i++) {
            freqs[s[i] - 'a']++;
            freqp[p[i] - 'a']++;
        }
        vector<int> ans;
        int i = 0, j = m - 1;
        while (j < n) {
            if (freqs == freqp) { 
                ans.push_back(i);
            }
            freqs[s[i] - 'a']--;
            i++;
            j++;
            if (j < n) {
                freqs[s[j] - 'a']++;
            }
        }
        return ans;
    }
};
