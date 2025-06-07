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
// vvi lca in complete tree; haing node value equal to index;
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int a=queries[i][0];
            int b=queries[i][1];
            int count=0;
            while(a!=b){
                if(b>a){
                    b=b/2;
                }   
                else{
                    a=a/2;
                }
                count++;
            }
            ans[i]=count+1;
        }
        return ans;
    }
};