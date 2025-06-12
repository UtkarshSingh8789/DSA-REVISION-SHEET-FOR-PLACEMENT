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
//LEARN ABOUT TAKING TRANSPOSE OF MATRIX;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);

            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};