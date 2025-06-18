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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n=numCourses;
        int m=prerequisites.size();
        unordered_map<int,list<int>> adjList;
        vector<int> indegree(n,0);
        vector<vector<bool>> pre(n,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adjList[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto frontNode=q.front();
            q.pop();
            for(auto nbr:adjList[frontNode]){
                pre[frontNode][nbr]=true;
                for(int i=0;i<n;i++){
                    if(pre[i][frontNode]==true){
                        pre[i][nbr]=true;
                    }
                }
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        int k=queries.size();
        for(int i=0;i<k;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(pre[u][v]==true){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};