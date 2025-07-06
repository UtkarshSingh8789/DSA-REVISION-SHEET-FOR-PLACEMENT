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

//VVII 


// class Solution {
//   public:
//     int celebrity(vector<vector<int> >& mat) {
//         // code here
//         int n=mat.size();
//         vector<int> indegree(n,0);
//         unordered_map<int,unordered_set<int>> adjList;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(j!=i and mat[i][j]==1){
//                     adjList[j].insert(i);
//                     indegree[i]++;
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(indegree[i]==0){
//                 if(adjList[i].size()==(n-1)) return i;
//             }
//         }
//         return -1;
//     }
// };
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(mat[i][j]==1){
                i=i+1;
            }
            else if(mat[j][i]==1){
                j=j-1;
            }
            else{
                i++;
                j--;
            }
        }
        if(i>j) return -1;
        int ans=i;
        for(int j=0;j<n;j++){
            if(i!=j && mat[i][j]==1) return -1;
            if(mat[j][i]==0) return -1;
        }
        return ans;
    }
};