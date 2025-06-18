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

// we have to reverse the edges because taking about outdegree that why reverse and think like kahn's algorithm;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,vector<int>> adjList;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto nbr:graph[i]){
                adjList[nbr].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int frontNode=q.front();
            ans.push_back(frontNode);
            q.pop();
            for(auto nbr:adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};